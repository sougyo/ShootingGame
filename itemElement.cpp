#include "itemElement.h"

using itemutil::Item;
using itemutil::ItemElement;
using itemutil::ItemKind;

gameutil::MovePattern ItemElement::movePattern(-0.01,0,1);
int ItemElement::count = 0;


ItemElement::ItemElement(Item* owner, double x, double y, const ItemKind* itemKind) 
		: gameutil::Moveable(x, y, 1, gamemath::toRadian(-90), 0) {
	this->owner = owner;
	this->itemKind = itemKind;
	
	count++;
}

ItemElement::~ItemElement(void) {
	count--;
}

void ItemElement::fire(int x, int y) {
	this->x += x;
	this->y += y;
	isActive_ = true;
}

void ItemElement::move(void) {
	if (isActive_) {
		movePattern.move(this);
		if (isOutOfDisplay())
			toInactive();
	}
}

void ItemElement::draw(void) {
	if (isAppearance()) {
		itemKind->getImage()->drawImage(0, getX(), getY());
	}
}

void ItemElement::checkCollision(gamesystem::Fighter* fighter) {
	if (gameutil::checkCollision(this, fighter, getRadius() + fighter->getImageRadius())) {
		itemKind->caughtProcess(this);
		toInactive();
		gamesoundutil::DirectSound::getInstance()->playGameSE(2);
	}

}

void ItemElement::toInactive(void) {
	isActive_ = false;
	owner->activeCount--;
}