#include "itemFactory.h"

using std::string;
using std::istringstream;
using itemutil::Item;
using itemutil::ItemKind;
using factory::ItemFactory;

namespace itemutil {
	int x[] = {0, -10, -26, -10, 2, -16, 0, 20, 26, 2, -22, -14, -28, 8, -6, -10, -6, 12, 16, 24, 28, -28, 10, -20, -2, 28, -6, 12, 8, 2, 12};
	int y[] = {0, -28, 20, -4, -2, 10, 8, -20, 12, -6, -12, -14, 22, 18, -6, -24, 22, 18, 28, -28, 24, -10, 20, 14, 6, -18, 4, 14, -22, 8, -12};
}

ItemFactory::ItemFactory(void) {
}

ItemFactory::~ItemFactory(void) {
}

Item* ItemFactory::createItem(string str) {
	if (str == "null")
		return new Item;

	Item* item = new Item;
		
	istringstream in(str);
	char kind;
	int n;
	int index = 0;
	int size = sizeof(itemutil::x);
	
	in >> kind >> n;
	while (in) {
		for (int i = 0; i < n; i++) {
			const ItemKind* itemKind = 
					itemutil::ItemKindMap::getInstance()->getItemKind(kind);
			assert(itemKind != 0);
			item->addItemElement(itemutil::x[index % size], itemutil::y[index % size], itemKind);
			index++;
		}
		in >> kind >> n;
	}
	return item;
}
