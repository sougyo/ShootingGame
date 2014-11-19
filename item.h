#ifndef ___ITEM_H
#define ___ITEM_H

#include <cassert>
#include <vector>
#include "gamefwd.h"
#include "itemKind.h"

namespace itemutil {
	class Item;
}

#include "itemElement.h"

class itemutil::Item {
private:
	friend class itemutil::ItemElement;
	
private:
	bool isActive_;
	int activeCount;
	std::vector<itemutil::ItemElement*> itemElements;

private:
	Item(const itemutil::Item&);
	const itemutil::Item& operator=(const itemutil::Item&);
	
public:
	Item(void);
	~Item(void);

public:
	void addItemElement(double, double, const itemutil::ItemKind*);
	
public:
	void fire(int, int);
	void move(void);
	void draw(void);
	void checkCollision(gamesystem::Fighter*);
	
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) const { return static_cast<int>(itemElements.size()); }
	itemutil::ItemElement* getItemElement(int);
};

#endif // ___ITEM_H