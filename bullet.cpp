#include "bullet.h"

using bulletutil::Bullet;
using bulletutil::BulletElement;
using graphics::Image;
using gameutil::MovePattern;

Bullet::Bullet(int maxSize, gameutil::MovePattern* movePattern, Image* image, bool isBeam) : maxSize(maxSize), size(0), isActive_(false), isBeam(isBeam), activeCount(0), image(image) {
	bulletElements = new BulletElement[maxSize];
	this->movePattern = movePattern;
	radius = static_cast<int>(image->getRadius() * 0.8);
}

Bullet::~Bullet(void) {
	delete[] bulletElements;
	delete movePattern;
}

void Bullet::addBulletElement(double x, double y, double vr, double vtheta, int time) {
	assert(time >= 0);
	assert(size < maxSize);
	bulletElements[size++] = BulletElement(this, x, y, vr, gamemath::toRadian(vtheta), -time);
}

void Bullet::fire(int x, int y) {
	if (!isActive_) {
		isActive_ = true;
		activeCount = size;
		for (int i = 0; i < size; i++)
			bulletElements[i].fire(x, y);
	}
}

void Bullet::move(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++)
			bulletElements[i].move();
		if (activeCount == 0)
			isActive_ = false;
	}
}

void Bullet::draw(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++)
			bulletElements[i].draw();
	}
}

void Bullet::checkCollision(bombutil::Bomb* bomb) {
	int distance = getRadius() + bomb->getRadius();
	for (int i = 0; i < size; i++)
		bulletElements[i].checkCollision(bomb, distance);
}

void Bullet::checkCollision(gamesystem::Fighter* fighter) {
	if (fighter->isInvincibility())
		return;
	int distance = getRadius() + fighter->getRadius();
	for (int i = 0; i < size; i++)
		bulletElements[i].checkCollision(fighter, distance);
}

void Bullet::rotate(double angle) {
	for (int i = 0; i < size; i++)
		bulletElements[i].rotate(angle);
}

void Bullet::translate(double vx, double vy) {
	for (int i = 0; i < size; i++)
		bulletElements[i].translate(vx, vy);
}

void Bullet::deleteExtraBulletElement(void) {
	for (int i = 0; i < size; i++)
		bulletElements[i].deleteExtraBulletElement();
}

BulletElement* Bullet::getBulletElement(int index) {
	assert(index >= 0 && index < size);
	return &bulletElements[index];
}

#include <iostream>
void Bullet::dump(void) {
	std::cout << "\n--BulletDumpStart" << std::endl;
	for (int i = 0; i < size; i++)
		bulletElements[i].dump();
	movePattern->dump();
	std::cout << "--BulletDumpEnd\n" << std::endl;
}
