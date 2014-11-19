#ifndef ___ENEMY_POOL_FACTORY_H
#define ___ENEMY_POOL_FACTORY_H

#include <algorithm>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include "constantField.h"
#include "enemy.h"
#include "enemyPool.h"
#include "enemyPoolElement.h"
#include "enemyFile.h"
#include "enemyFileReader.h"

namespace factory {
    class EnemyPoolFactory;
}

class factory::EnemyPoolFactory {
private:
    EnemyPoolFactory(const factory::EnemyPoolFactory&);
    const factory::EnemyPoolFactory& operator=(const factory::EnemyPoolFactory&);
    
public:
    EnemyPoolFactory(void);
    ~EnemyPoolFactory(void);
    
public:
    enemyutil::EnemyPool* createEnemyPool(std::string, std::string);
    
private:
    std::vector<enemyIO::EnemyFile*>* createEnemyFiles(std::string);
    enemyutil::Enemy* createEnemy(std::string, std::vector<enemyIO::EnemyFile*>*);
    enemyutil::EnemyPool* createEnemyPool(std::string, std::vector<enemyIO::EnemyFile*>*);
};

#endif // ___ENEMY_POOL_FACTORY_H
