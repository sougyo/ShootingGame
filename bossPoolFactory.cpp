#include "bossPoolFactory.h"

using std::count;
using std::istringstream;
using std::replace;
using std::string;
using bossutil::Boss;
using bossutil::BossPool;
using bossutil::BossPoolElement;
using bossIO::BossFile;
using bossIO::BossFileReader;
using factory::BossFactory;
using factory::BossPoolFactory;

BossPoolFactory::BossPoolFactory(void) {
}

BossPoolFactory::~BossPoolFactory(void) {
}

BossPool* BossPoolFactory::createBossPool(string bossStr) {
	BossPool* bossPool = new BossPool;
	
	int line = static_cast<int>(count(bossStr.begin(), bossStr.end(), '\n'));
	replace(bossStr.begin(), bossStr.end(), ',', ' ');
	assert(line == count(bossStr.begin(), bossStr.end(), ' '));
	istringstream in(bossStr);
	
	string fileName;
	int time;
	for (int i = 0; i < line; i++) {
		in >> fileName;
		in >> time;
		bossPool->addPoolElement(new BossPoolElement(createBoss(fileName), time));
	}
	
	return bossPool;
}

Boss* BossPoolFactory::createBoss(string fileName) {
	BossFileReader bossFileReader(gameutil::DATA_PATH.c_str(), fileName.c_str());
	BossFile* bossFile = bossFileReader.createBossFile();
	BossFactory bossFactory;
	Boss* boss = bossFactory.createBoss(bossFile);
	delete bossFile;
	
	return boss;
}
