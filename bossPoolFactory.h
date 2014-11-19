#ifndef ___BOSS_POOL_FACTORY_H
#define ___BOSS_POOL_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "boss.h"
#include "bossFactory.h"
#include "bossFile.h"
#include "bossFileReader.h"
#include "bossPool.h"
#include "bossPoolElement.h"
#include "constantField.h"

namespace factory {
	class BossPoolFactory;
}

class factory::BossPoolFactory {
private:
	BossPoolFactory(const factory::BossPoolFactory&);
	const factory::BossPoolFactory& operator=(const factory::BossPoolFactory&);
	
public:
	BossPoolFactory(void);
	~BossPoolFactory(void);
	
public:
	bossutil::BossPool* createBossPool(std::string);
	
private:
	bossutil::Boss* createBoss(std::string);
};

#endif // ___BOSS_POOL_FACTORY_H