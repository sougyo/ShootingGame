#include "bossElement.h"

using bossutil::BossElement;
using graphics::Image;
using enemyutil::Enemy;

gameutil::Table<Enemy>* BossElement::enemyTable = 0;
gamesystem::GameInformation* BossElement::gameInformation = 0;

BossElement::BossElement(int limit, Image* techniqueImage, Enemy* enemy) : isActive_(false), numberDisplay(2, 353, 15) {
	this->limit = limit;
	this->techniqueImage = techniqueImage;
	this->enemy = enemy;
}

BossElement::~BossElement(void) {
	delete enemy;
}

void BossElement::fire(void) {
	if (!isActive_) {
		isActive_ = true;
		enemyTable->add(enemy, 0, 0);
	}
}

void BossElement::move(void) {
	if (isActive_) {
		limit--;
		if (limit <= 0) {
			enemy->kill();
			gameInformation->addScore(30000);
		}
		if (!enemy->isActive()) {
			gameInformation->addScore(100000);
			isActive_ = false;
			return;
		}
	}
}

void BossElement::draw(void) {
	if (isActive_) {
		numberDisplay.draw(limit/60);
	}
}
