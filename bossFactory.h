#ifndef ___BOSS_FACTORY_H
#define ___BOSS_FACTORY_H

#include "boss.h"
#include "bossFile.h"
#include "bossFileElement.h"
#include "constantField.h"
#include "enemy.h"
#include "enemyFile.h"
#include "Image.h"
#include "ImageFactory.h"

namespace factory {
    class BossFactory;
}

class factory::BossFactory {
private:
    BossFactory(const factory::BossFactory&);
    const factory::BossFactory& operator=(const factory::BossFactory&);
    
public:
    BossFactory(void);
    ~BossFactory(void);
    
public:
    bossutil::Boss* createBoss(const bossIO::BossFile*);
};

#endif // ___BOSS_FACTORY_H
