#include "missile.h"

using gameutil::MovePattern;
using missileutil::Missile;
using missileutil::MissileElement;
using graphics::Image;

Missile::Missile(int maxSize, MovePattern* movePattern, Image* image) : maxSize(maxSize), size(0), activeCount(0), isActive_(false) {
	this->movePattern = movePattern;
	this->image = image;
	missileElements = new MissileElement*[maxSize];
}

Missile::~Missile(void) {
	for (int i = 0; i < size; i++)
		delete missileElements[i];
	delete[] missileElements;
	delete movePattern;
}

void Missile::addMissileElement(double x, double y, double vr, double vtheta, int time) {
	assert(size < maxSize);
	missileElements[size++] = new MissileElement(this, x, y, vr, gamemath::toRadian(vtheta), -time);
}

void Missile::fire(int, int) {
	if (!isActive_) {
		isActive_ = true;
		activeCount = size;
		for (int i = 0; i < size; i++)
			missileElements[i]->fire();
	}
}

void Missile::move(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++) {
			missileElements[i]->move();
		}
		if (activeCount == 0)
			isActive_ = false;
	}
}

void Missile::draw(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++)
			missileElements[i]->draw();
	}
}

MissileElement* Missile::getMissileElement(int index) {
	assert(index >= 0 && index < size);
	return missileElements[index];
}