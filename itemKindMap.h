#ifndef ___ITEM_KIND_MAP_H
#define ___ITEM_KIND_MAP_H

#include <cassert>
#include <vector>
#include "constantField.h"
#include "gameInformation.h"
#include "itemElement.h"
#include "imageFactory.h"
#include "itemKind.h"

namespace itemutil {
	class ItemKindMap;
	void up(gamesystem::GameInformation&, itemutil::ItemElement*);
	void power(gamesystem::GameInformation&, itemutil::ItemElement*);
	void bpower(gamesystem::GameInformation&, itemutil::ItemElement*);
	void full(gamesystem::GameInformation&, itemutil::ItemElement*);
	void bomb(gamesystem::GameInformation&, itemutil::ItemElement*);
	void point(gamesystem::GameInformation&, itemutil::ItemElement*);
	void collect(gamesystem::GameInformation&, itemutil::ItemElement*);
}

class itemutil::ItemKindMap {
private:
	static itemutil::ItemKindMap singleton;

private:
	std::vector<const itemutil::ItemKind*> itemKinds;
	
private:
	ItemKindMap(const itemutil::ItemKindMap&);
	const itemutil::ItemKindMap& operator=(const itemutil::ItemKindMap&);
	ItemKindMap(void);
	~ItemKindMap(void);

public:
	static itemutil::ItemKindMap* getInstance(void) { return &singleton; }
	
public:
	const itemutil::ItemKind* getItemKind(char);
	void initialize(void);
};

#endif // ___ITEM_KIND_MAP_H