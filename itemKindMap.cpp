#include "itemKindMap.h"

using graphics::ImageFactory;
using itemutil::ItemElement;
using itemutil::ItemKindMap;
using itemutil::ItemKind;
using gamesystem::GameInformation;
using gameutil::ITEM_IMAGE_PATH;

ItemKindMap ItemKindMap::singleton;

ItemKindMap::ItemKindMap(void) {
}

ItemKindMap::~ItemKindMap(void) {
	for (int i = 0; i < static_cast<int>(itemKinds.size()); i++)
		delete itemKinds.at(i);
}

const ItemKind* ItemKindMap::getItemKind(char kind) {
	for (int i = 0; i < static_cast<int>(itemKinds.size()); i++) {
		if (itemKinds.at(i)->getKindChar() == kind)
			return itemKinds.at(i);
	}
	return 0;
}

void ItemKindMap::initialize(void) {
	itemKinds.clear();
	assert(itemKinds.size() == 0);
	itemKinds.push_back(new ItemKind('t', itemutil::point, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "point(15,15).png").c_str()), 0));
	itemKinds.push_back(new ItemKind('p', itemutil::power, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "power(20,20).png").c_str())
		, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "extend(10,10).png").c_str())));
	itemKinds.push_back(new ItemKind('P', itemutil::bpower, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "bpower(24,24).png").c_str())
		, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "extend(10,10).png").c_str())));
	itemKinds.push_back(new ItemKind('u', itemutil::up, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "up(24,24).png").c_str()), 0));
	itemKinds.push_back(new ItemKind('f', itemutil::full, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "full(24,24).png").c_str()), 0));
	itemKinds.push_back(new ItemKind('b', itemutil::bomb, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "bomb(24,24).png").c_str()), 0));
	itemKinds.push_back(new ItemKind('o', itemutil::collect, ImageFactory::getInstance()->createImage((ITEM_IMAGE_PATH + "collect(15,15).png").c_str()), 0));
}

void itemutil::up(GameInformation& gameInfo, ItemElement*) {
	gameInfo.addPlayer();
}

void itemutil::power(GameInformation& gameInfo, ItemElement*) {
	gameInfo.addPower();
}

void itemutil::bpower(GameInformation& gameInfo, ItemElement*) {
	gameInfo.addPower(gameutil::BIG_POWER);
}

void itemutil::full(GameInformation& gameInfo, ItemElement*) {
	gameInfo.addPower(gameutil::POWER_MAX);
}

void itemutil::bomb(GameInformation& gameInfo, ItemElement*) {
	gameInfo.addBomb();
}

void itemutil::point(GameInformation& gameInfo, ItemElement* itemElement) {
	gameInfo.addScore((gameutil::HEIGHT - itemElement->getY() + 10) * 300);
}

void itemutil::collect(GameInformation&, ItemElement*) {
	
}