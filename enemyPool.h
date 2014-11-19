#ifndef ___ENEMY_POOL_H
#define ___ENEMY_POOL_H

#include "pool.h"

namespace enemyutil {
	class EnemyPool;
}

class enemyutil::EnemyPool : public gameutil::Pool {
private:
	EnemyPool(const enemyutil::EnemyPool&);
	const enemyutil::EnemyPool& operator=(const enemyutil::EnemyPool&);
	
public:
	EnemyPool(void);
	~EnemyPool(void);
	
public:
	void move(void);
};

#endif // ___ENEMY_POOL_H
