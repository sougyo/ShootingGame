#include "bulletFileElement.h"

using bulletIO::BulletFileElement;
using std::string;

int BulletFileElement::count = 0; // �f�o�b�O�p

BulletFileElement::BulletFileElement(string name, string image, string isStr, string mpStr) {
	bulletName = name;
	imageFileName = image;
	initialStateString = isStr;
	movePatternString = mpStr;
	
	count++; // �f�o�b�O�p
}

BulletFileElement::BulletFileElement(const BulletFileElement& element) {
	bulletName = element.bulletName;
	imageFileName = element.imageFileName;
	initialStateString = element.initialStateString;
	movePatternString = element.movePatternString;
	
	count++; // �f�o�b�O�p
}

BulletFileElement::~BulletFileElement(void) {
	count--; // �f�o�b�O�p
}

BulletFileElement& BulletFileElement::operator=(const BulletFileElement& element) {
	if (this != &element) {
		bulletName = element.bulletName;
		imageFileName = element.imageFileName;
		initialStateString = element.initialStateString;
		movePatternString = element.movePatternString;
	}
	return *this;
}

#include <iostream>
using std::cout;
using std::endl;
void BulletFileElement::dump(void) const {
	cout << "bulletName:" << bulletName << '\n'
		 << "imageFileName:" << imageFileName << '\n'
		 << "---initialStateString\n" << initialStateString
		 << "---movePatternString\n" << movePatternString << endl;
}