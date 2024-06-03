#pragma once
#include "Iterator.h"
#include "FS.h"
class EFATIter :
    public Iterator<Cluster>
{
private:
	FS* exfat;
    unsigned int Count;
	unsigned int Cursor;
public:
	EFATIter(FS* fsItem) : Iterator(fsItem->ClusterCount()) {
		exfat = fsItem;
		Count = exfat->ClusterCount();
        Cursor = 0;
    }
    void First() { Cursor = 0; }
    void Next() { Cursor ++; }
    bool IsDone() const { return (Cursor >= Count); }
    Cluster GetCurrent();
};

