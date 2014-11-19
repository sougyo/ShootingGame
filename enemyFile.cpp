#include "enemyFile.h"

using enemyutil::Enemy;
using enemyIO::EnemyFile;
using enemyIO::EnemyFileElement;
using factory::EnemyFactory;

EnemyFile::EnemyFile(bulletIO::BulletFile* bulletFile) {
	assert(bulletFile);
	this->bulletFile = bulletFile;
}

EnemyFile::~EnemyFile(void) {
	delete bulletFile;
}

void EnemyFile::addEnemyFileElement(EnemyFileElement enemyFileElement) {
	enemyFileElements.push_back(enemyFileElement);
}

const EnemyFileElement* EnemyFile::getEnemyFileElement(int index) const {
	assert(index < getSize());
	return &enemyFileElements[index];
}

const EnemyFileElement* EnemyFile::searchEnemyFileElement(std::string str) const {
	for (int i = 0; i < getSize(); i++) {
		if (enemyFileElements[i].getEnemyName() == str)
			return &enemyFileElements[i];
	}
	return 0;
}

Enemy* EnemyFile::createEnemy(std::string enemyName) {
	EnemyFactory enemyFactory;
	const EnemyFileElement* enemyFileElement = searchEnemyFileElement(enemyName);
	assert(enemyFileElement);
	return enemyFactory.createEnemy(this, *enemyFileElement);
}

void EnemyFile::dump(void) {
	for (int i = 0; i < getSize(); i++)
		enemyFileElements[i].dump();
	bulletFile->dump();
}