//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "AnalysThread.h"
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include "MainUnit.h"
#include "FS.h"
#include "NTFS.h"
#include "windows.h"
#include "IteratorDecorator.h"
#include "FSIteratorDecorator.h"
#include "FAT16.h"
#include "EFAT.h"
#include "FAT32.h"
#include "MyFSC.h"
#include "FileSystemCreator.h"
#include "ReadThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall read_thread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall ReadThread::ReadThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	 FreeOnTerminate = true;

	 UnicodeString tempString = Form1->Edit2->Text;
	 LPCWSTR databasePath = tempString.c_str();

	 AnalysThreadObject = new AnalysThread(false, databasePath);

}
//---------------------------------------------------------------------------
void __fastcall ReadThread::Execute()
{
	while(!Terminated)
	{
		// ждать когда будут подготовлены данные к след анализу
		//---- Place thread code here ----
		DWORD startTime = GetTickCount();
		FileSystemCreator* fsCreator = new MyFSC;
		//LPCWSTR logicDisk = L"\\\\.\\C:";

		UnicodeString tempString = Form1->Edit1->Text;
		logicDisk = tempString.c_str();

		FSEnum fsType = DetectFS(logicDisk);
		Synchronize(UpdateFS);
		FS* fs = fsCreator->CreateFileSystem(fsType, logicDisk);
		if (!fs->Init(logicDisk)) {
			throw  "Cannot open logic disk";
		};
		clusterCount = fs->ClusterCount();
		unsigned int clusterSize = fs->ClusterSize();
		FileTypeEnum selectFileType = GetFileType();
		Iterator<Cluster>* it = new FSIteratorDecorator(
			new EFATIter(fs),
			selectFileType
		);

		for (it->First();!it->IsDone() && !Terminated;it->Next()) {
			Cluster currentObject = it->GetCurrent();
			clusters += 1;
			// анализ в доп потоке

			// передаем данные на обработку
			AnalysThreadObject->Send(&currentObject);
			AnalysThreadObject->DataReadyEvent->SetEvent();

			while(AnalysThreadObject->DataCopiedEvent->WaitFor(3000) != wrSignaled)
			{ }

			AnalysThreadObject->DataCopiedEvent->ResetEvent();
			Synchronize(UpdateLabel2);
		}

		DWORD endTime = GetTickCount();
		processTime = endTime - startTime ;

		UnicodeString timestr = UnicodeString(processTime);
		Synchronize(UpdateLabel);
        break;
	}

	AnalysThreadObject->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall ReadThread::UpdateLabel()
{
	UnicodeString timestr = UnicodeString(processTime);
	Form1->SearchTimeResultLabel->Caption = timestr;

}
void __fastcall ReadThread::UpdateLabel2()
{
	Form1->CountResultLabel->Caption = clusters;

}

void __fastcall ReadThread::UpdateFS()
{
	Form1->DetectResultLabel->Caption = DetectedFS;
}

FSEnum __fastcall ReadThread::DetectFS(LPCWSTR device) {
    HANDLE fileHandler = CreateFileW(
        device,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template

    if (fileHandler == INVALID_HANDLE_VALUE)
	{
		throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
	}
	DWORD bytesRead;
    BYTE buffer[2048];
	// Считывание первых 2048 байт
	if (!ReadFile(fileHandler, buffer, sizeof(buffer), &bytesRead, nullptr)) {
        throw "Error reading volume\n";
    }

	// Проверка сигнатуры NTFS
	BYTE ntfsSignature[] = { 0x4E, 0x54, 0x46, 0x53 };
	if (memcmp(buffer + 3, ntfsSignature, sizeof(ntfsSignature)) == 0) {
		DetectedFS = L"NTFS";
		return FSEnum::NTFS;
    }
	// Проверка сигнатуры FAT16
	BYTE fat16Signature[] = { 0x46, 0x41, 0x54, 0x31, 0x36 };
	if (memcmp(buffer + 35, fat16Signature, sizeof(fat16Signature)) == 0) {
		DetectedFS = L"FAT16";
        return FSEnum::FAT16;
	}
	// Проверка сигнатуры FAT32
	BYTE fat32Signature[] = { 0x46, 0x41, 0x54, 0x33, 0x32 };
	if (memcmp(buffer + 52, fat32Signature, sizeof(fat32Signature)) == 0) {
		DetectedFS = L"FAT32";
		return FSEnum::FAT32;
	}
	// Проверка сигнатуры ExFAT
	BYTE exfatSignature[] = { 0x45, 0x58, 0x46, 0x41, 0x54 };
	if (memcmp(buffer + 3, exfatSignature, sizeof(exfatSignature)) == 0) {
		DetectedFS = L"EXFAT";
		return FSEnum::ExFAT;
	}
    throw "Cannot detect fs!";
}
FileTypeEnum __fastcall ReadThread::GetFileType()
{
	if(Form1->ExeButton->Checked){
		return  FileTypeEnum::Exe;
	}
	if(Form1->JpegButton->Checked){
		return  FileTypeEnum::Jpeg;
	}
	if(Form1->PngButton->Checked){
		return  FileTypeEnum::Png;
	}
	if(Form1->BinButton->Checked){
		return  FileTypeEnum::Bin;
	}
	return FileTypeEnum::Pdf;
}
