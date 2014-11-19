#include "bossFactory.h"

using bossutil::Boss;
using bossIO::BossFile;
using bossIO::BossFileElement;
using enemyutil::Enemy;
using enemyIO::EnemyFile;
using graphics::Image;
using graphics::ImageFactory;
using factory::BossFactory;

BossFactory::BossFactory(void) {
}

BossFactory::~BossFactory(void) {
}

Boss* BossFactory::createBoss(const BossFile* bossFile) {
	Image* bossNameImage = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + bossFile->getBossNameImageString()).c_str());
	Image* bossSubNameImage = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH +bossFile->getBossSubNameImageString()).c_str());
	
	Boss* boss = new Boss(bossNameImage, bossSubNameImage);
	
	EnemyFile* enemyFile = bossFile->getEnemyFile();
	for (int i = 0; i < bossFile->getSize(); i++) {
		const BossFileElement* bossFileElement = bossFile->getBossFileElement(i);

		int limit = bossFileElement->getLimit();
		Image* techImage = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH +bossFileElement->getTechniqueImageFileName()).c_str());
		Enemy* enemy = enemyFile->createEnemy(bossFileElement->getEnemyName());
		
		assert(enemy);
		
		boss->addBossElement(limit + 1, techImage, enemy);
	}
	
	return boss;
}