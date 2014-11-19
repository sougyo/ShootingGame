#include "enemyFileElement.h"

using std::string;
using enemyIO::EnemyFileElement;

int EnemyFileElement::count = 0; // �f�o�b�O�p

EnemyFileElement::EnemyFileElement(string enemyName, string imageFileName, int hp, bool canCollide_, string isStr, string mpStr, string bpStr, string imStr, string opStr) {
	this->enemyName		= enemyName;
	this->imageFileName = imageFileName;
	this->hp = hp;
	this->canCollide_ = canCollide_;
	this->initialStateString	= isStr;
	this->movePatternString		= mpStr;
	this->bulletPatternString	= bpStr;
	this->imagePatternString	= imStr;
	this->optionPatternString	= opStr;
	
	count++; // �f�o�b�O�p
}

EnemyFileElement::~EnemyFileElement(void) {
	count--; // �f�o�b�O�p
}

EnemyFileElement::EnemyFileElement(const EnemyFileElement& element) {
	enemyName		= element.enemyName;
	imageFileName	= element.imageFileName;
	hp = element.hp;
	canCollide_ = element.canCollide_;
	initialStateString	= element.initialStateString;
	movePatternString	= element.movePatternString;
	bulletPatternString	= element.bulletPatternString;
	imagePatternString	= element.imagePatternString;
	optionPatternString	= element.optionPatternString;
	
	count++; // �f�o�b�O�p
}

EnemyFileElement& EnemyFileElement::operator=(const EnemyFileElement& element) {
	if (this != &element) {
		enemyName		= element.enemyName;
		imageFileName	= element.imageFileName;
		hp = element.hp;
		canCollide_ = element.canCollide_;
		initialStateString	= element.initialStateString;
		movePatternString	= element.movePatternString;
		bulletPatternString	= element.bulletPatternString;
		imagePatternString	= element.imagePatternString;
		optionPatternString	= element.optionPatternString;
	}
	return *this;
}

#include <iostream> //�f�o�b�O�p
void EnemyFileElement::dump(void) {
	std::cout << "enemyName:" << enemyName << '\n'
			  << "imageFileName:" << imageFileName << '\n'
			  << "hp:" << hp << '\n'
			  << "canCollide:" << canCollide_ << '\n'
			  << "IS > \n" << initialStateString
			  << "MP > \n" << movePatternString
			  << "BP > \n" << bulletPatternString
			  << "IP > \n" << imagePatternString
			  << "OP > \n" << optionPatternString
			  << std::endl;
}