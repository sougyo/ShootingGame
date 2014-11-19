#ifndef ___EFFECT_FACTORY_H
#define ___EFFECT_FACTORY_H

#include <algorithm>
#include <string>
#include <sstream>
#include "constantField.h"
#include "effect.h"
#include "ImageFactory.h"

namespace factory {
    class EffectFactory;
}

class factory::EffectFactory {
private:
    EffectFactory(const factory::EffectFactory&);
    const factory::EffectFactory& operator=(const factory::EffectFactory&);
    
public:
    EffectFactory(void);
    ~EffectFactory(void);
    
public:
    effectutil::Effect* createEffect(std::string);
};

#endif // ___EFFECT_FACTORY_H
