#include "bomb.h"

using bombutil::Bomb;
using gameutil::Moveable;
using gamesystem::GameInformation;

gamesystem::GameInformation* Bomb::gameInformation = 0;

Bomb::Bomb(void) : Moveable(0, 0, 0, 0, 0) {
	lock = 0;
	radius = 0;
	image = graphics::ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + "active.png").c_str());
}

Bomb::~Bomb(void) {
}

void Bomb::fire(int x, int y) {
	if (isActive() || gameInformation->getBomb() == 0)
		return;
	radius = 0;
	isActive_ = true;
	this->x = x;
	this->y = y;
	gameInformation->subtractBomb();
	lock = 70;
}

void Bomb::move(void) {
	if (isActive()) {
		lock--;
		radius += 5;
		if (lock <= 0)
			isActive_ = false;
	}
}

void Bomb::draw(void) {
	if (isActive()) {
		int radius = this->radius + 20;
		const int sqrtRadius = static_cast<int>(radius / std::sqrt(2.0));
		image->drawImage(0, getX(), getY() - radius);
		image->drawImage(0, getX(), getY() + radius);
		image->drawImage(0, getX() - radius, getY());
		image->drawImage(0, getX() + radius, getY());
		image->drawImage(0, getX() + sqrtRadius, getY() + sqrtRadius);
		image->drawImage(0, getX() - sqrtRadius, getY() + sqrtRadius);
		image->drawImage(0, getX() + sqrtRadius, getY() - sqrtRadius);
		image->drawImage(0, getX() - sqrtRadius, getY() - sqrtRadius);
	}
}
