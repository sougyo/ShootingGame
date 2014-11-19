#include "angle.h"

using labelutil::Angle;

Angle::Angle(void) {
	xangle = 0;
	yangle = 0;
	zangle = 0;
}

Angle::Angle(double xangle, double yangle, double zangle) {
	this->xangle = xangle;
	this->yangle = yangle;
	this->zangle = zangle;
}

Angle::~Angle(void) {
}

void Angle::setAngle(double xangle, double yangle, double zangle) {
	this->xangle = xangle;
	this->yangle = yangle;
	this->zangle = zangle;
}

void Angle::addAngle(const Angle& angle) {
	this->xangle += angle.getXangle();
	this->yangle += angle.getYangle();
	this->zangle += angle.getZangle();
}