#include "labelMovePattern.h"

using gamemath::toRadian;
using labelutil::Angle;
using labelutil::LabelMovePatternElement;
using labelutil::LabelMovePattern;

LabelMovePattern::LabelMovePattern(void) {
	initialize();
}

LabelMovePattern::~LabelMovePattern(void) {
}

void LabelMovePattern::addLabelMovePatternElement(double ar, double atheta, double aphi, double xangle, double yangle, double zangle, int time) {
	LabelMovePatternElement element;
	element.ar = ar;
	element.atheta = toRadian(atheta);
	element.aphi = toRadian(aphi);
	element.aangle = Angle(toRadian(xangle), toRadian(yangle), toRadian(zangle));
	element.time = time;
	labelMovePatternElements.push_back(element);
	initTime.push_back(time);
}

void LabelMovePattern::move(double& vr, double& vtheta, double& vphi, Angle& vangle) {
	if (isActive_) {
		assert(0 <= index && index <= getSize());
		if (index == getSize()) {
			isActive_ = false;
			return;
		}
		vr += labelMovePatternElements[index].ar;
		vtheta += labelMovePatternElements[index].atheta;
		vphi += labelMovePatternElements[index].aphi;
		vangle.addAngle(labelMovePatternElements[index].aangle);
		labelMovePatternElements[index].time--;
		if (labelMovePatternElements[index].time <= 0)
			index++;
	}
}

void LabelMovePattern::initialize(void) {
	index = 0;
	isActive_ = true;
	for (int i = 0; i < getSize(); i++) {
		labelMovePatternElements[i].time = initTime[i];
	}
}
