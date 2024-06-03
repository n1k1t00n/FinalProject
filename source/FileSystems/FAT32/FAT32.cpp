#include "FAT32.h"
#include <iostream>
#include "Iterator.h"
#include "windows.h"
#include "stdio.h"
using namespace std;
bool FAT32::ReadClusterSize()
{
    BYTE sector[512];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);
    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = 0;
	if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        throw std::invalid_argument("Set FilePointer error");
        CloseHandle(fileHandler);
        return false;
	}
    if (!ReadFile(fileHandler, sector, bytesToRead, &bytesRead, NULL))
    {
        throw std::invalid_argument("ReadFile error");
        CloseHandle(fileHandler);
        return false;
    }
	BootRecord* pBootRecord = reinterpret_cast<BootRecord*>(sector);
	unsigned int sectorSize = (pBootRecord->sectorSize);
	unsigned int countSectors = 0;
	if (pBootRecord->countSectors16 != 0) {
		countSectors = static_cast<int>(pBootRecord->countSectors16);
	}
	else if (pBootRecord->countSectors32 != 0) {
		countSectors = static_cast<int>(pBootRecord->countSectors32);
	}
	unsigned int classCoeff = static_cast<int>(pBootRecord->classCoeff);
	clusterSize = sectorSize * classCoeff;
	clusterCount = countSectors / classCoeff;
	return true;
}