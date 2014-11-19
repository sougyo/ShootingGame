#include "talkEventPoolElement.h"

using gameutil::PoolElement;
using talkeventutil::TalkEvent;
using talkeventutil::TalkEventPoolElement;

gameutil::Table<talkeventutil::TalkEvent>* TalkEventPoolElement::talkEventTable = 0;
gameutil::Table<enemyutil::Enemy>* TalkEventPoolElement::enemyTable = 0;
gameutil::Table<bulletutil::Bullet>* TalkEventPoolElement::bulletTable = 0;
effectutil::EffectPool* TalkEventPoolElement::clearEffectPool = 0;

TalkEventPoolElement::TalkEventPoolElement(TalkEvent* talkEvent, int time) : PoolElement(time) {
	this->talkEvent = talkEvent;
}

TalkEventPoolElement::~TalkEventPoolElement(void) {
	delete talkEvent;
}

void TalkEventPoolElement::execute(void) {
	bulletutil::Bullet** bullets = bulletTable->getArray();
	for (int i = 0; i < bulletTable->getSize(); i++) {
		if (bullets[i] == 0)
			continue;
		if (!bullets[i]->isActive())
			continue;
		for (int j = 0; j < bullets[i]->getSize(); j++) {
			bulletutil::BulletElement* bulletElement = bullets[i]->getBulletElement(j);
			if (bulletElement->isAppearance())
				clearEffectPool->fire(bulletElement->getX(), bulletElement->getY());
		}
	}
	bulletTable->clear();
	enemyTable->clear();
	talkEventTable->add(talkEvent, 0, 0);
}

bool TalkEventPoolElement::isActive(void) {
	return talkEvent->isActive();
}
