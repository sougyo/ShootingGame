#ifndef ___ITEM_FACTORY_H
#define ___ITEM_FACTORY_H

#include <cassert>
#include <string>
#include <sstream>
#include "item.h"
#include "itemKindMap.h"

namespace factory {
    class ItemFactory;
}

class factory::ItemFactory {
private:
    ItemFactory(const factory::ItemFactory&);
    const factory::ItemFactory& operator=(const factory::ItemFactory&);
    
public:
    ItemFactory(void);
    ~ItemFactory(void);
    
public:
    itemutil::Item* createItem(std::string);
};

#endif // ___ITEM_FACTORY_H
