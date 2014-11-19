#include "itemKind.h"

using graphics::Image;
using itemutil::ItemKind;

gamesystem::GameInformation* ItemKind::gameInformation = 0;

ItemKind::ItemKind(char kind, void (*func)(gamesystem::GameInformation&, itemutil::ItemElement*), Image* image1, Image* image2) : kind(kind), func(func), image1(image1), image2(image2) {
}

ItemKind::~ItemKind(void) {
}

void ItemKind::caughtProcess(itemutil::ItemElement* itemElement) const {
	func(*gameInformation, itemElement);
}

Image* ItemKind::getImage(void) const {
	if (gameInformation->isFullPower() && image2 != 0)
		return image2;
	return image1;
}
