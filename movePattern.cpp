#include "movePattern.h"
#include "enemy.h"

using std::string;
using std::cos;
using std::sin;
using enemyutil::Enemy;
using enemyutil::EnemyElement;
using gameutil::Moveable;
using gameutil::MovePattern;
using gameutil::MovePatternElement;

gamesystem::Fighter* MovePattern::fighter = 0;
gameutil::Table<enemyutil::Enemy>* MovePattern::enemyTable = 0;
gameutil::Table<enemyutil::Enemy>* MovePattern::bossEnemyTable = 0;

int MovePattern::count = 0; // デバッグ用

MovePattern::MovePattern(int maxSize) : maxSize(maxSize), size(0), currentTime(0) {
	movePatternElements = new MovePatternElement[maxSize];
	
	count++; // デバッグ用
}

MovePattern::MovePattern(double ar, double atheta, unsigned time) : maxSize(1), size(0), currentTime(0) {
	movePatternElements = new MovePatternElement[1];
	add(ar, atheta, time);
	
	count++; // デバッグ用
}

MovePattern::~MovePattern(void) {
	delete[] movePatternElements;
	
	count--; // デバッグ用
}

void MovePattern::add(double ar, double atheta, unsigned time) {
	assert(size < maxSize);
	currentTime += time;
	movePatternElements[size].ar = ar;
	if (atheta > Normal)
		movePatternElements[size].atheta = atheta;
	else
		movePatternElements[size].atheta = gamemath::toRadian(atheta);
	movePatternElements[size].time = currentTime;
	size++;
}

void MovePattern::move(Moveable* moveable) {
	if (moveable->time < 0) {
		moveable->time++;
		return;
	}
	checkIndex(&moveable->movePatternIndex, moveable->time);
	int index = moveable->movePatternIndex;
	assert(index < size && index >= 0);
	if (isAim(index)) {
		moveable->vtheta = getAimTheta(moveable);
	} else if (isHoming(index)) {
		moveable->vtheta = getHomingTheta(moveable);
	} else {
		moveable->vr += movePatternElements[index].ar;
		moveable->vtheta += movePatternElements[index].atheta;
	}
	moveable->x += moveable->getVX();
	moveable->y += moveable->getVY();
	moveable->time++;
}

void MovePattern::checkIndex(int* movePatternIndex, int time) {
	if (time == static_cast<int>(movePatternElements[*movePatternIndex].time)
					&& *movePatternIndex < size-1)
		(*movePatternIndex)++;
}

double MovePattern::getAimTheta(Moveable* moveable) {
	return std::atan2(fighter->getY() - moveable->y, fighter->getX() - moveable->x);
}

double MovePattern::getHomingTheta(gameutil::Moveable* moveable) {
	Enemy** bossEnemys = bossEnemyTable->getArray();
	for (int i = 0; i < bossEnemyTable->getSize(); i++) {
		if (bossEnemys[i] == 0)
			continue;
		if (!bossEnemys[i]->isActive())
			continue;

		return std::atan2(bossEnemys[i]->getEnemyElement(0)->getY() - moveable->y, bossEnemys[i]->getEnemyElement(0)->getX() - moveable->x);
	}

	Enemy** enemys = enemyTable->getArray();
	Enemy* enemy = 0;
	EnemyElement* enemyElement = 0;
	for (int i = 0; i < enemyTable->getSize(); i++) {
		if (enemys[i] == 0)
			continue;
		if (!enemys[i]->isActive())
			continue;

		enemy = enemys[i];
		break;
	}
	
	if (enemy == 0)
		return moveable->getVtheta();

	for (int i = 0; i < enemy->getSize(); i++) {
		if (enemy->getEnemyElement(i)->isAppearance()) {
			enemyElement = enemy->getEnemyElement(i);
			break;
		}
	}

	if (enemyElement == 0)
		return moveable->getVtheta();
	
	return std::atan2(enemyElement->getY() - moveable->y, enemyElement->getX() - moveable->x);
}

#include <iostream>
void MovePattern::dump(void) {
	std::cout << "- movePatternElements -" << std::endl;
	std::cout << "ar\tatheta\ttime" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << movePatternElements[i].ar << '\t'
			 << movePatternElements[i].atheta << '\t'
			 << movePatternElements[i].time << std::endl;
	}
}
