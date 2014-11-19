#include "enemyPoolFactory.h"

using std::string;
using std::vector;
using std::count;
using std::istringstream;
using std::replace;
using factory::EnemyPoolFactory;
using enemyutil::Enemy;
using enemyutil::EnemyPool;
using enemyutil::EnemyPoolElement;
using enemyIO::EnemyFile;
using enemyIO::EnemyFileReader;

EnemyPoolFactory::EnemyPoolFactory(void) {
}

EnemyPoolFactory::~EnemyPoolFactory(void) {
}

EnemyPool* EnemyPoolFactory::createEnemyPool(string enemyFilesString, string interpreterString) {
	vector<EnemyFile*>* enemyFiles = createEnemyFiles(enemyFilesString);
	EnemyPool* enemyPool = createEnemyPool(interpreterString, enemyFiles);
	
	for (int i = 0; i < static_cast<int>(enemyFiles->size()); i++)
		delete enemyFiles->at(i);
	delete enemyFiles;
	
	return enemyPool;
}

vector<EnemyFile*>* EnemyPoolFactory::createEnemyFiles(string efStr) {
	vector<EnemyFile*>* enemyFiles = new vector<EnemyFile*>;
	int line = static_cast<int>(count(efStr.begin(), efStr.end(), '\n'));
	istringstream in(efStr);
	string fileName;
	for (int i = 0; i < line; i++) {
		in >> fileName;
		EnemyFileReader* enemyFileReader = new EnemyFileReader(gameutil::DATA_PATH.c_str(), fileName.c_str());
		EnemyFile* enemyFile = enemyFileReader->createEnemyFile();
		enemyFiles->push_back(enemyFile);
		delete enemyFileReader;
	}
	
	return enemyFiles;
}

Enemy* EnemyPoolFactory::createEnemy(string enemyName, vector<EnemyFile*>* enemyFiles) {
	for (int i = 0; i < static_cast<int>(enemyFiles->size()); i++) {
		if (enemyFiles->at(i)->searchEnemyFileElement(enemyName)) {
			Enemy* enemy = enemyFiles->at(i)->createEnemy(enemyName);
			assert(enemy);
			return enemy;
		}
	}
	return 0;
}

EnemyPool* EnemyPoolFactory::createEnemyPool(string itpStr, vector<EnemyFile*>* enemyFiles) {
	int line = static_cast<int>(count(itpStr.begin(), itpStr.end(), '\n'));
	replace(itpStr.begin(), itpStr.end(), ',', ' ');
	assert(line*3 == count(itpStr.begin(), itpStr.end(), ' '));
	istringstream in(itpStr);
	
	EnemyPool* enemyPool = new EnemyPool;
	for (int i = 0; i < line; i++) {
		string enemyName;
		double x;
		double y;
		unsigned time;
		in >> enemyName >> x >> y >> time;
		
		Enemy* enemy = createEnemy(enemyName, enemyFiles);
		assert(enemy);
		enemyPool->addPoolElement(new EnemyPoolElement(enemy, static_cast<int>(x), static_cast<int>(y), static_cast<int>(time)));
	}
	
	return enemyPool;
}
