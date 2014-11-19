#include "bossFileElement.h"

using std::string;
using bossIO::BossFileElement;

BossFileElement::BossFileElement(int limit, string techImageFileName, string enemyName) {
	this->limit = limit;
	this->techniqueImageFileName = techImageFileName;
	this->enemyName = enemyName = enemyName;
}

BossFileElement::~BossFileElement(void) {
}
