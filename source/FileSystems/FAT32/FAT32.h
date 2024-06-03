#pragma once
#include "FS.h"
#include "Iterator.h"

class FAT32 :
	public FS
{
private:
	#pragma pack(push, 1)
	typedef struct {
		BYTE padding1[11];
		uint16_t sectorSize;
		uint8_t classCoeff;
		BYTE padding2[5];
		uint16_t countSectors16;
		BYTE padding3[11];
		uint32_t countSectors32;
	} BootRecord;
	#pragma pack(pop)
protected:
	// В разных ФС различается только процесс получения размера кластера
	bool ReadClusterSize();
};

