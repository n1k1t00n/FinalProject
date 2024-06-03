#include "MyFSC.h"
#include "FileSystemCreator.h"
#include "NTFS.h"
#include "FAT16.h"
#include "EFAT.h"
#include "FAT32.h"
#include <stdexcept>

FS* MyFSC::CreateFileSystem(FSEnum fsType, LPCWSTR device)
{
	switch (fsType) {
	case FSEnum::NTFS: {
		NTFS* fs = new NTFS();
		fs->Init(device);
		return fs;
	}
	case FSEnum::FAT16: {
		FAT16* fs = new FAT16();
		fs->Init(device);
		return fs;
	}
	case FSEnum::ExFAT: {
		EFAT* fs = new EFAT();
		fs->Init(device);
		return fs;
	}
	case FSEnum::FAT32: {
		FAT32* fs = new FAT32();
		fs->Init(device);
		return fs;
	}
	default:
		throw std::invalid_argument("Set FilePointer error");
		return NULL;
	}
}
