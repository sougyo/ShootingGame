#include "missileFileElement.h"

using std::string;
using missileIO::MissileFileElement;

MissileFileElement::MissileFileElement(int interval, string imageFileName, string initialStateString, string movePatternString) {
	this->interval = interval;
	this->imageFileName = imageFileName;
	this->initialStateString = initialStateString;
	this->movePatternString = movePatternString;
}

MissileFileElement::~MissileFileElement(void) {
}
