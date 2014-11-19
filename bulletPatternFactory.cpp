#include "bulletPatternFactory.h"

using std::replace;
using std::count;
using std::string;
using std::istringstream;
using std::ostringstream;
using factory::BulletPatternFactory;
using bulletutil::BulletPattern;
using bulletIO::BulletFile;
using bulletIO::BulletFileElement;

BulletPatternFactory::BulletPatternFactory(const BulletFile* bulletFile) {
	this->bulletFile = bulletFile;
}

BulletPatternFactory::~BulletPatternFactory(void) {
}

BulletPattern* BulletPatternFactory::createBulletPattern(std::string bpStr) {
	int line = static_cast<int>(count(bpStr.begin(), bpStr.end(), '\n'));
	changeKeyStringToValueString(&bpStr);
	replace(bpStr.begin(), bpStr.end(), ',', ' ');
	
	assert(line*2 == count(bpStr.begin(), bpStr.end(), ' '));
	
	istringstream in(bpStr);
	BulletPattern* bulletPattern = new BulletPattern();
	for (int i = 0; i < line; i++) {
		string bulletName;
		double angle;
		int time;
		
		in >> bulletName >> angle >> time;
		const BulletFileElement* bfe = bulletFile->searchBulletFileElement(bulletName);
		assert(bfe);
		
		if (time == BulletPattern::Killed)
			bulletPattern->addKilledBulletFileElement(bfe, angle);
		else
			bulletPattern->addBulletPatternElement(bfe, angle, time);
	}

	return bulletPattern;
}

void BulletPatternFactory::changeKeyStringToValueString(string* str) {
	replaceAll(str, "killed", BulletPattern::Killed);
	replaceAll(str, "follow", BulletPattern::Follow);
	replaceAll(str, "this", BulletPattern::Dynamic);
}

void BulletPatternFactory::replaceAll(string* str, string oldStr, int newValue) {
	unsigned currentIndex;
	ostringstream out;
	out << newValue;
	string newStr = out.str();
	
	currentIndex = static_cast<unsigned>(str->find(oldStr.c_str()));
	while (currentIndex != str->npos) {
		str->replace(currentIndex, oldStr.size(), newStr);
		currentIndex = static_cast<unsigned>(str->find(oldStr.c_str()));
	}
}