#include "boss.h"

using bossutil::Boss;
using bossutil::BossElement;
using enemyutil::Enemy;
using graphics::Image;

gameutil::Table<bulletutil::Bullet>* Boss::bulletTable = 0;
gameutil::Table<enemyutil::Enemy>* Boss::enemyTable = 0;

Boss::Boss(Image* bossNameImage, Image* bossSubNameImage) : isActive_(false), index(0), gauge(40, 10) {
	this->bossNameImage = bossNameImage;
	this->bossSubNameImage = bossSubNameImage;
}

Boss::~Boss(void) {
	for (int i = 0; i < getSize(); i++)
		delete bossElements[i];
}


void Boss::addBossElement(int limit, Image* techniqueImage, Enemy* enemy) {
	bossElements.push_back(new BossElement(limit * 60, techniqueImage, enemy));
	gauge.add(enemy->getHp(0));
}

void Boss::fire(int, int) {
	if (!isActive_) {
		isActive_ = true;
		bossElements[index]->fire();
	}
}

void Boss::move(void) {
	if (isActive_) {
		bossElements[index]->move();
		if (!bossElements[index]->isActive()) {
			if (index == getSize() - 1) {
				isActive_ = false;
				return;
			}
			index++;
			bulletTable->clear();
			enemyTable->clear();
			bossElements[index]->fire();
		}
	}
}

void Boss::draw(void) {
	if (isActive_) {
		bossElements[index]->draw();
		bossNameImage->drawImage(0, 30, 30);
		gauge.draw(index, bossElements[index]->getHp());
	}
}
