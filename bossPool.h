#ifndef ___BOSS_POOL_H
#define ___BOSS_POOL_H

#include "pool.h"
#include "DirectSound.h"
#include "BackgroundController.h"

namespace bossutil {
	class BossPool;
}

class bossutil::BossPool : public gameutil::Pool {
private:
	gamesoundutil::DirectSound* directSound;
	bool isFirst;

private:
	BossPool(const bossutil::BossPool&);
	const bossutil::BossPool& operator=(const bossutil::BossPool&);
	
public:
	BossPool(void);
	~BossPool(void);
	
public:
	void move(void);
};

#endif // ___BOSS_POOL_H