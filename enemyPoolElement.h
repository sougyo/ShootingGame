#ifndef ___ENEMY_POOL_ELEMENT_H
#define ___ENEMY_POOL_ELEMENT_H

#include "enemy.h"
#include "poolElement.h"
#include "table.h"

namespace enemyutil {
    class EnemyPoolElement;
}

class enemyutil::EnemyPoolElement : public gameutil::PoolElement {
public:
    static gameutil::Table<enemyutil::Enemy>* enemyTable;
    
private:
    enemyutil::Enemy* enemy;
    int x;
    int y;

private:
    EnemyPoolElement(const enemyutil::EnemyPoolElement&);
    const enemyutil::EnemyPoolElement& operator=(const enemyutil::EnemyPoolElement&);
    
public:
    EnemyPoolElement(enemyutil::Enemy*, int, int, int);
    ~EnemyPoolElement(void);
    
public:
    void execute(void);
    bool isActive(void);
};

#endif // ___ENEMY_POOL_ELEMENT_H
