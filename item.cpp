#include "item.h"

using itemutil::Item;
using itemutil::ItemElement;
using itemutil::ItemKind;

Item::Item(void) : isActive_(false), activeCount(0) {
}

Item::~Item(void) {
	for (int i = 0; i < getSize(); i++)
		delete itemElements[i];
}

void Item::addItemElement(double x, double y, const ItemKind* itemKind) {
	itemElements.push_back(new ItemElement(this, x, y, itemKind));
}

void Item::fire(int x, int y) {
	if (!isActive_) {
		isActive_ = true;
		activeCount = getSize();
		for (int i = 0; i < getSize(); i++)
			itemElements[i]->fire(x, y);
	}
}

void Item::move(void) {
	if (isActive_) {
		for (int i = 0; i < getSize(); i++)
			itemElements[i]->move();
		if (activeCount == 0)
			isActive_ = false;
	}
}

void Item::draw(void) {
	if (isActive_) {
		for (int i = 0; i < getSize(); i++)
			itemElements[i]->draw();
	}
}

void Item::checkCollision(gamesystem::Fighter* fighter) {
	for (int i = 0; i < getSize(); i++)
		itemElements[i]->checkCollision(fighter);
}

ItemElement* Item::getItemElement(int index) {
	assert(index >= 0 && index < getSize());
	return itemElements[index];
}