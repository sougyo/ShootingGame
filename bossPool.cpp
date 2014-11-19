#include "bossPool.h"

using bossutil::BossPool;

BossPool::BossPool(void) {
	directSound = gamesoundutil::DirectSound::getInstance();
	isFirst = true;
}

BossPool::~BossPool(void) {
}

void BossPool::move(void) {
	if (isActive_) {
		if (isFirst) {
			directSound->stop();
			directSound->setTrack(directSound->getNextTrack());
			directSound->play();
			background::BackgroundController::getInstance()->nextState();
			isFirst = false;
		}

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
