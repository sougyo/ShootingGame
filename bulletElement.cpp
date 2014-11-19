#include "bulletElement.h"

using std::sin;
using std::cos;
using bulletutil::BulletElement;
using gameutil::Moveable;
using gamesystem::Fighter;

effectutil::EffectPool* BulletElement::effectPool = 0;
gamesystem::GameInformation* BulletElement::gameInformation = 0;

int BulletElement::count = 0; // デバッグ用

BulletElement::BulletElement(void) {
	owner = 0;
	isGraze = false;
	
	count++; // デバッグ用
}

BulletElement::BulletElement(bulletutil::Bullet* owner, double x, double y, double vr, double vtheta, int time) 
		: Moveable(x, y, vr, vtheta, time) {
	this->owner = owner;
	isGraze = false;
	
	count++; // デバッグ用
}

BulletElement::~BulletElement(void) {
	count--; // デバッグ用
}

BulletElement::BulletElement(const BulletElement& bulletElement) {
	owner			 = bulletElement.owner;
	x				 = bulletElement.x;
	y				 = bulletElement.y;
	vr				 = bulletElement.vr;
	vtheta			 = bulletElement.vtheta;
	time			 = bulletElement.time;
	isActive_		 = bulletElement.isActive_;
	movePatternIndex = bulletElement.movePatternIndex;
	isGraze			 = bulletElement.isGraze;
	
	count++; // デバッグ用
}

BulletElement& BulletElement::operator=(const BulletElement& bulletElement) {
	if (&bulletElement != this) {
		owner			 = bulletElement.owner;
		x				 = bulletElement.x;
		y				 = bulletElement.y;
		vr				 = bulletElement.vr;
		vtheta			 = bulletElement.vtheta;
		time			 = bulletElement.time;
		isActive_		 = bulletElement.isActive_;
		movePatternIndex = bulletElement.movePatternIndex;
		isGraze			 = bulletElement.isGraze;
	}
	return *this;
}

void BulletElement::fire(int x, int y) {
	this->x += x;
	this->y += y;
	isActive_ = true;
}

void BulletElement::move(void) {
	if (isActive_) {
		owner->movePattern->move(this);
		if (isOutOfDisplay())
			toInactive();
	}
}

void BulletElement::draw(void) {
	if (isAppearance()) {
		owner->image->drawImage(vtheta, getX(), getY());
	}
}

void BulletElement::checkCollision(bombutil::Bomb* bomb, int distance) {
	if (gameutil::checkCollision(this, bomb, distance)) {
		effectPool->fire(getX(), getY());
		toInactive();
	}
}

void BulletElement::checkCollision(Fighter* fighter, int distance) {
	if (gameutil::checkCollision(this, fighter, distance)) {
		toInactive();
		fighter->collision();
	} else if (!isGraze) {
		if (gameutil::checkCollision(this, fighter, distance + 15)) {
			isGraze = true;
			gameInformation->addGraze();
		}
	}
}

void BulletElement::rotate(double angle) {
	vtheta += angle;
	double tempx = x;
	double tempy = y;
	x = tempx * cos(angle) - tempy * sin(angle);
	y = tempx * sin(angle) + tempy * cos(angle);
}

void BulletElement::deleteExtraBulletElement(void) {
	if (isActive_ && time < 0)
		toInactive();
}

void BulletElement::toInactive(void) {
	isActive_ = false;
	owner->activeCount--;
}

#include <iostream>
void BulletElement::dump(void) {
	std::cout << x << ' ' << y << ' ' << vr << ' ' << vtheta << ' ' << time << std::endl;
}