#include "effectFile.h"

using std::string;
using effectIO::EffectFile;

EffectFile::EffectFile(void) {
}

EffectFile::~EffectFile(void) {
}

void EffectFile::addEffectElement(string effectString) {
	effectElements.push_back(effectString);
}

string EffectFile::getEffectString(int index) {
	assert(0 <= index && index < getSize());
	return effectElements[index];
}