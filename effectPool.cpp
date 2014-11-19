#include "effectPool.h"

using std::string;
using effectutil::Effect;
using effectutil::EffectPool;
using factory::EffectFactory;
using gameutil::Table;

Table<Effect>* EffectPool::effectTable = 0;

EffectPool::EffectPool(int size, string effectString) {
    EffectFactory effectFactory;
    for (int i = 0; i < size; i++)
        effects.push_back(effectFactory.createEffect(effectString));
}

EffectPool::~EffectPool(void) {
    for (int i = 0; i < getSize(); i++)
        delete effects[i];
}

void EffectPool::fire(int x, int y) {
    for (int i = 0; i < getSize(); i++) {
        if (!effects[i]->isActive()) {
            effectTable->add(effects[i], x, y);
            break;
        }
    }
}

void EffectPool::clean(void) {
    for (int i = 0; i < getSize(); i++) {
        effects[i]->clean();
    }
}
