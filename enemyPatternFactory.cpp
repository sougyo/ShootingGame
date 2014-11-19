#include "enemyPatternFactory.h"

using std::count;
using std::replace;
using std::istringstream;
using std::string;
using enemyutil::EnemyPattern;
using enemyIO::EnemyFile;
using enemyIO::EnemyFileElement;
using factory::EnemyPatternFactory;

EnemyPatternFactory::EnemyPatternFactory(const EnemyFile* enemyFile) {
	this->enemyFile = enemyFile;
}

EnemyPatternFactory::~EnemyPatternFactory(void) {
}

EnemyPattern* EnemyPatternFactory::createEnemyPattern(string epStr) {
	int line = static_cast<int>(count(epStr.begin(), epStr.end(), '\n'));
	replace(epStr.begin(), epStr.end(), ',', ' ');
	
	assert(line == count(epStr.begin(), epStr.end(), ' '));
	
	istringstream in(epStr);
	EnemyPattern* enemyPattern = new EnemyPattern(enemyFile);
	for (int i = 0; i < line; i++) {
		string enemyName;
		int time;
		
		in >> enemyName >> time;
		
		const EnemyFileElement* enemyFileElement = enemyFile->searchEnemyFileElement(enemyName);
		assert(enemyFileElement);
		enemyPattern->addEnemyPatternElement(enemyFileElement, time);
	}
	return enemyPattern;
}
