#include "titlePool.h"

using titleutil::TitlePool;

TitlePool::TitlePool(void) {
}

TitlePool::~TitlePool(void) {
}

void TitlePool::move(void) {
	if (isActive_) {
		if (index == getSize()) {
			isActive_ = false;
			return;
		}
		poolElements[index]->advanceTime();
		if (poolElements[index]->getTime() == 0) {
			poolElements[index]->execute();
			index++;
		}
	}
}
