#include "enemyFactory.h"

using std::count;
using std::istringstream;
using std::replace;
using std::string;
using bulletutil::BulletPattern;
using bulletIO::BulletFile;
using enemyutil::Enemy;
using enemyutil::EnemyPattern;
using enemyIO::EnemyFile;
using enemyIO::EnemyFileElement;
using factory::BulletPatternFactory;
using factory::EnemyFactory;
using factory::EnemyPatternFactory;
using factory::ImagePatternFactory;
using factory::MovePatternFactory;
using factory::ItemFactory;
using gameutil::ImagePattern;
using gameutil::MovePattern;
using itemutil::Item;

EnemyFactory::EnemyFactory(void) {
}

EnemyFactory::~EnemyFactory(void) {
}

Enemy* EnemyFactory::createEnemy(const EnemyFile* enemyFile, const EnemyFileElement& efe) {
	MovePatternFactory mpFactory;
	MovePattern* mp = mpFactory.createMovePattern(efe.getMovePatternString());
	BulletPatternFactory bpFactory(enemyFile->getBulletFile());
	BulletPattern* bp = bpFactory.createBulletPattern(efe.getBulletPatternString());
	EnemyPatternFactory epFactory(enemyFile);
	EnemyPattern* ep = epFactory.createEnemyPattern(efe.getOptionPatternString());
	ImagePatternFactory ipFactory;
	ImagePattern* ip = ipFactory.createImagePattern(efe.getImagePatternString());
	
	graphics::Image* image = graphics::ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + efe.getImageFileName()).c_str());

	int size = countLine(efe.getInitialStateString());
	
	Enemy* enemy = new Enemy(size, efe.getHp(), efe.canCollide(), mp, bp, ep, ip, image);
	analyzeInitialState(efe.getInitialStateString(), enemy);
	
	return enemy;
}

int EnemyFactory::countLine(string str) {
	return static_cast<int>(count(str.begin(), str.end(), '\n'));
}

void EnemyFactory::analyzeInitialState(string isStr, Enemy* enemy) {
	int line = static_cast<int>(count(isStr.begin(), isStr.end(), '\n'));
	int comma = static_cast<int>(count(isStr.begin(), isStr.end(), ','));
	
	assert(line*7 == comma);
	
	replace(isStr.begin(), isStr.end(), ',', ' ');
	istringstream in(isStr);
	
	for (int i = 0; i < line; i++) {
		double x;
		double y;
		double vr;
		double vtheta;
		unsigned time;
		int delay;
		double angle;
		string itemStr;
		
		in >> x >> y >> vr >> vtheta >> time >> delay >> angle >> itemStr;
		ItemFactory itemFactory;
		Item* item = itemFactory.createItem(itemStr);
		assert(item);
		enemy->addEnemyElement(x, y, vr, vtheta, time, delay, angle, item);
	}
}
