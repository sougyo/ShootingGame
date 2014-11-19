#include "missileSet.h"

using missileutil::MissileSet;
using missileutil::Missile;

gameutil::Table<Missile>* MissileSet::missileTable = 0;

MissileSet::MissileSet(int totalTime) : totalTime(totalTime) {
}

MissileSet::~MissileSet(void) {
	for (int i = 0; i < getSize(); i++)
		delete missiles[i];
}

void MissileSet::addMissile(missileutil::Missile* missile) {
	missiles.push_back(missile);
}

Missile* MissileSet::getMissile(int index) {
	assert(index >= 0 && index < getSize());
	return missiles[index];
}

void MissileSet::fire(int power) {
	int level = (getSize()-1) * power / gameutil::POWER_MAX;
	assert(0 <= level && level < getSize());
	for (int i = 0; i <= level; i++)
		missileTable->add(missiles[i], 0, 0);
}

bool MissileSet::isActive(void) {
	bool result = false;
	for (int i = 0; i < getSize(); i++) {
		if (missiles[i]->isActive())
			result = true;
	}
	return result;
}
