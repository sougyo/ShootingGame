#include "missileFile.h"

using missileIO::MissileFile;
using missileIO::MissileFileElement;

MissileFile::MissileFile(int totalTime) {
	this->totalTime = totalTime;
}

MissileFile::~MissileFile(void) {
	for (int i = 0; i < getSize(); i++)
		delete missileFileElements[i];
}

void MissileFile::addMissileFileElement(MissileFileElement* missileFileElement) {
	missileFileElements.push_back(missileFileElement);
}

const MissileFileElement* MissileFile::getMissileFileElement(int index) const {
	assert(index < getSize());
	return missileFileElements[index];
}
