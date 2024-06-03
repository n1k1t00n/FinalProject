#include "Cluster.h"
#include <iostream>
using namespace std;

Cluster::~Cluster()
{
    delete[] content;
}

FileTypeEnum Cluster::GetFileType()
{
    if (content[0] == 0x4D && content[1] == 0x5A) {
        return  FileTypeEnum::Exe;
	}
	else if (content[0] == 0xFF && content[1] == 0xD8 && content[2] == 0xFF && (content[3] == 0xE0 || content[3] == 0xE1  || content[3] == 0xDB)) {
		return  FileTypeEnum::Jpeg;
	}
	else if (content[0] == 0x89 && content[1] == 0x50 && content[2] == 0x4E && content[3] == 0x47 && content[4] == 0x0D && content[5] == 0x0A && content[6] == 0x1A && content[7] == 0x0A) {
		return  FileTypeEnum::Png;
	}
	else if (content[0] == 0x25 && content[1] == 0x50 && content[2] == 0x44 && content[3] == 0x46 && content[4] == 0x2D) {
		return  FileTypeEnum::Pdf;
	}
	else if (content[0] == 0x53 && content[1] == 0x50 && content[2] == 0x30 && content[3] == 0x31) {
		return  FileTypeEnum::Bin;
	}
	return FileTypeEnum::Underfind;
}
// Списки сигнатур: https://ru.wikipedia.org/wiki/Список_сигнатур_файлов

Cluster::Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize)
{
	content = new BYTE[100];
	std::memcpy(content, data, sizeof(BYTE) * 100);
    clusterNum = num;
}
void Cluster::SetContent(BYTE* data,unsigned int ClusterSize)
{
	content = new BYTE[100];
	std::memcpy(content, data, sizeof(BYTE) * 100);
}
