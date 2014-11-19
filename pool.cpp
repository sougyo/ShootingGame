#include "pool.h"

using gameutil::Pool;
using gameutil::PoolElement;

Pool::Pool(void) : index(0), isActive_(false) {
}

Pool::~Pool(void) {
	for (int i = 0; i < getSize(); i++)
		delete poolElements[i];
}

void Pool::addPoolElement(PoolElement* poolElement) {
	poolElements.push_back(poolElement);
}

void Pool::start(void) {
	isActive_ = true;
	index = 0;
}

bool Pool::isFinish(void) {
	if (getSize() != index)
		return false;
	
	return !poolElements[getSize() - 1]->isActive();
}
