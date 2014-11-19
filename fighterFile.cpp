#include "fighterFile.h"

using std::string;
using gamesystemIO::FighterFile;

FighterFile::FighterFile(int radius, double highSpeed, double slowSpeed, string imageFileName, string missileFileName) {
	this->radius = radius;
	this->highSpeed = highSpeed;
	this->slowSpeed = slowSpeed;
	this->imageFileName = imageFileName;
	this->missileFileName = missileFileName;
}

FighterFile::~FighterFile(void) {
}
