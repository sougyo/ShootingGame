#include "poolScheduler.h"

using gameutil::Pool;
using gameutil::PoolScheduler;

PoolScheduler::PoolScheduler(void) : index(0), isActive_(false) {
}

PoolScheduler::~PoolScheduler(void) {
	for (int i = 0; i < getSize(); i++)
		delete pools[i];
}

void PoolScheduler::addPool(Pool* pool) {
	pools.push_back(pool);
}

void PoolScheduler::start(void) {
	for (int i = 0; i < getSize(); i++)
		pools[i]->start();
	index = 0;
	isActive_ = true;
}

void PoolScheduler::move(void) {
	if (isActive_) {
		if (index == getSize()) {
			isActive_ = false;
			return;
		}
		pools[index]->move();
		if (pools[index]->isFinish())
			index++;
	}
}

Pool* PoolScheduler::getPool(void) {
	if (index < getSize())
		return pools[index];
	else
		return pools[0];
}
