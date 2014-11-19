#include "label.h"

using std::sin;
using std::cos;
using gamemath::toRadian;
using graphics::Image;
using labelutil::Label;
using labelutil::LabelMovePattern;

Label::Label(int x, int y, int z, double vr, double vtheta, double vphi, Image* image, LabelMovePattern* labelMovePattern) {
	this->image = image;
	this->labelMovePattern = labelMovePattern;
	
	initX = x;
	initY = y;
	initZ = z;
	initVr = vr;
	initVtheta = toRadian(vtheta);
	initVphi =toRadian(vphi);
	isActive_ = false;
}

Label::~Label(void) {
	delete labelMovePattern;
}

void Label::fire(int x, int y) {
	if (!isActive_) {
		isActive_ = true;
		
		this->x = initX;
		this->y = initY;
		this->z = initZ;
		this->vr = initVr;
		this->vtheta = initVtheta;
		this->vphi = initVphi;
		Angle initAngle;
		this->angle = initAngle;
		this->vangle = initAngle;
		
		this->x += x;
		this->y += y;
		
		labelMovePattern->initialize();
	}
}

void Label::move(void) {
	if (isActive_) {
		if (!labelMovePattern->isActive())
			isActive_ = false;
		labelMovePattern->move(vr, vtheta, vphi, vangle);
		
		x += vr * sin(vphi) * cos(vtheta);
		y += vr * sin(vphi) * sin(vtheta);
		z += vr * cos(vphi);
		angle.addAngle(vangle);
	}
}

void Label::draw(void) {
	if (isActive_) {
		image->drawImage(angle.getXangle(), angle.getYangle(), angle.getZangle(), getX(), getY(), getZ());
	}
}
