#ifndef ___FIGHTER_FACTORY_H
#define ___FIGHTER_FACTORY_H

#include "constantField.h"
#include "gamefwd.h"
#include "fighterFile.h"
#include "Image.h"
#include "ImageFactory.h"
#include "missileFile.h"
#include "missileFileReader.h"
#include "missileSetController.h"

namespace factory {
    class FighterFactory;
}

class factory::FighterFactory {
private:
    FighterFactory(const factory::FighterFactory&);
    const factory::FighterFactory& operator=(const factory::FighterFactory&);
    
public:
    FighterFactory(void);
    ~FighterFactory(void);
    
public:
    gamesystem::Fighter* createFighter(const gamesystemIO::FighterFile&);
};

#endif // ___FIGHTER_FACTORY_H
