#include "enemyPoolElement.h"

using enemyutil::Enemy;
using enemyutil::EnemyPoolElement;
using gameutil::PoolElement;

gameutil::Table<Enemy>* EnemyPoolElement::enemyTable = new gameutil::Table<Enemy>(0);

EnemyPoolElement::EnemyPoolElement(Enemy* enemy, int x, int y, int time) 
		: PoolElement(time) {
	this->enemy = enemy;
	this->x = x;
	this->y = y;
}

EnemyPoolElement::~EnemyPoolElement(void) {
	delete enemy;
}

void EnemyPoolElement::execute(void) {
	enemyTable->add(enemy, x, y);
}

bool EnemyPoolElement::isActive(void) {
	return false;
}