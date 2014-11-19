#include "enemyPool.h"

using enemyutil::EnemyPool;

EnemyPool::EnemyPool(void) {
}

EnemyPool::~EnemyPool(void) {
}

void EnemyPool::move(void) {
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
