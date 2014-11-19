#ifndef ___POOL_SCHEDULER_H
#define ___POOL_SCHEDULER_H

#include <vector>
#include "pool.h"

namespace gameutil {
	class PoolScheduler;
}

class gameutil::PoolScheduler {
private:
	std::vector<gameutil::Pool*> pools;
	int index;
	bool isActive_;
	
private:
	PoolScheduler(const gameutil::PoolScheduler&);
	const gameutil::PoolScheduler& operator=(const gameutil::PoolScheduler&);
	
public:
	PoolScheduler(void);
	~PoolScheduler(void);
	
public:
	void addPool(gameutil::Pool*);
	void start(void);
	void move(void);
	gameutil::Pool* getPool(void);
	inline int getSize(void) const { return static_cast<int>(pools.size()); }
	inline bool isActive(void) const { return isActive_; }
};

#endif // ___POOL_SCHEDULER_H
		   
