#ifndef ___ITEM_ELEMENT_H
#define ___ITEM_ELEMENT_H

#include "gamefwd.h"
#include "movePattern.h"
#include "moveable.h"
#include "gameMath.h"
#include "gameFunctions.h"
#include "item.h"
#include "itemKind.h"
#include "DirectSound.h"

class itemutil::ItemElement : public gameutil::Moveable {
private:
    itemutil::Item* owner;

private:
    static gameutil::MovePattern movePattern;
    
private:
    const itemutil::ItemKind* itemKind;

private:
    ItemElement(const itemutil::ItemElement&);
    const itemutil::ItemElement& operator=(const itemutil::ItemElement&);

public:
    ItemElement(itemutil::Item*, double, double, const itemutil::ItemKind*);
    ~ItemElement(void);
    
public:
    void fire(int, int);
    void move(void);
    void draw(void);
    void checkCollision(gamesystem::Fighter*);
    
    inline int getRadius(void) const { return static_cast<int>(itemKind->getImage()->getRadius() * 2.0); }
    inline const itemutil::ItemKind* getItemKind(void) const { return itemKind; }
    
private:
    void toInactive(void);
    
public:
    static int count;
};

#endif // ___ITEM_ELEMENT_H
