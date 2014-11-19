#ifndef ___POOL_SCHEDULER_FACTORY_H
#define ___POOL_SCHEDULER_FACTORY_H

#include <cassert>
#include <string>
#include <sstream>
#include "bossPool.h"
#include "bossPoolFactory.h"
#include "enemyPool.h"
#include "enemyPoolFactory.h"
#include "gameInformation.h"
#include "interpreterFile.h"
#include "pool.h"
#include "poolScheduler.h"
#include "titlePool.h"
#include "titlePoolFactory.h"
#include "talkEventPool.h"
#include "talkEventPoolFactory.h"

namespace factory {
	class PoolSchedulerFactory;
}

class factory::PoolSchedulerFactory {
private:
	std::istringstream* in;
	
private:
	PoolSchedulerFactory(const factory::PoolSchedulerFactory&);
	const factory::PoolSchedulerFactory& operator=(const factory::PoolSchedulerFactory&);
	
public:
	PoolSchedulerFactory(void);
	~PoolSchedulerFactory(void);
	
public:
	gameutil::PoolScheduler* createPoolScheduler(const interpreterIO::InterpreterFile&, const gamesystem::GameInformation&);
	
private:
	std::string readLine(void);
	gameutil::Pool* createEnemyPool(std::string, std::string&);
	gameutil::Pool* createPool(std::string&, std::string&, const gamesystem::GameInformation&);
};

#endif // ___POOL_SCHEDULER_FACTORY_H
