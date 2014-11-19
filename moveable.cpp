#include "moveable.h"

using gameutil::Moveable;

Moveable::Moveable(void) {
	this->x = 0;
	this->y = 0;
	this->vr = 0;
	this->vtheta = 0;
	this->time = 0;
	movePatternIndex = 0;
	isActive_ = false;
}

Moveable::Moveable(double x, double y, double vr, double vtheta, int time) {
	this->x = x;
	this->y = y;
	this->vr = vr;
	this->vtheta = vtheta;
	this->time = time;
	movePatternIndex = 0;
	isActive_ = false;
}

void Moveable::translate(double vx, double vy) {
	x += vx;
	y += vy;
}
