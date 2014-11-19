#ifndef ___POOL_H
#define ___POOL_H

#include <vector>
#include "poolElement.h"

namespace gameutil {
	class Pool;
}

class gameutil::Pool {
protected:
	std::vector<gameutil::PoolElement*> poolElements;
	int index;
	bool isActive_;
	
private:
	Pool(const gameutil::Pool&);
	const gameutil::Pool& operator=(const gameutil::Pool&);
	
public:
	Pool(void);
	virtual ~Pool(void);
	
public:
	void addPoolElement(gameutil::PoolElement*);
	void start(void);
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) const { return static_cast<int>(poolElements.size()); }
	
public:
	virtual void move(void) = 0;
	bool isFinish(void);
};

#endif // ___POOL_H
