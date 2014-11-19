#include "missileElement.h"

using missileutil::Missile;
using missileutil::MissileElement;

gamesystem::Fighter* MissileElement::fighter = 0;
int MissileElement::count = 0; // デバッグ用

MissileElement::MissileElement(Missile* owner, double x, double y, double vr, double vtheta, int time)
		: gameutil::Moveable(x, y, vr, vtheta, time) {
	this->owner = owner;
	initialState.x = x;
	initialState.y = y;
	initialState.vr = vr;
	initialState.vtheta = vtheta;
	initialState.time = time;
	
	count++; // デバッグ用
}
MissileElement::~MissileElement(void) {
	count--; // デバッグ用
}

void MissileElement::fire(void) {
	isActive_ = true;
	if (time == 0) {
		x += fighter->getX();
		y += fighter->getY();
	}
}

void MissileElement::move(void) {
	if (isActive_) {
		owner->movePattern->move(this);
		if (time == 0) {
			x += fighter->getX();
			y += fighter->getY();
		}
		if (isOutOfDisplay())
			toInactive();
	}
}

void MissileElement::draw(void) {
	if (isAppearance())
		owner->image->drawImage(0, getX(), getY());
}

void MissileElement::toInactive(void) {
	isActive_ = false;
	owner->activeCount--;
	x = initialState.x;
	y = initialState.y;
	vr = initialState.vr;
	vtheta = initialState.vtheta;
	time = initialState.time;
	movePatternIndex = 0;
}