#include "talkEventPool.h"

using talkeventutil::TalkEventPool;

TalkEventPool::TalkEventPool(void) {
}

TalkEventPool::~TalkEventPool(void) {
}

void TalkEventPool::move(void) {
    if (isActive_) {
        if (index == getSize()) {
            isActive_ = false;
            return;
        }
        if (poolElements[index]->getTime() >= 0) {
            poolElements[index]->advanceTime();
            if (poolElements[index]->getTime() == 0) {
                poolElements[index]->execute();
            }
        } else if (!poolElements[index]->isActive()) {
            index++;
        }
    }
}
