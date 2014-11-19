#include "bossPoolElement.h"

using bossutil::Boss;
using bossutil::BossPoolElement;
using gameutil::PoolElement;

gameutil::Table<Boss>* BossPoolElement::bossTable = 0;

BossPoolElement::BossPoolElement(Boss* boss, int time) : PoolElement(time) {
	this->boss = boss;
}

BossPoolElement::~BossPoolElement(void) {
	delete boss;
}

void BossPoolElement::execute(void) {
	bossTable->add(boss, 0, 0);
}

bool BossPoolElement::isActive(void) {
	return boss->isActive();
}
