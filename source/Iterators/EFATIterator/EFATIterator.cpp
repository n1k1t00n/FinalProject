#include "EFATIterator.h"

Cluster EFATIter::GetCurrent()
{
    Cluster item;
	if (!exfat->ReadCluster(&item, Cursor)) {
        throw std::invalid_argument("Error read cluster!");
    }
    return item;
}
