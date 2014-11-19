#ifndef ___POOL_ELEMENT_H
#define ___POOL_ELEMENT_H

namespace gameutil {
	class PoolElement;
}

class gameutil::PoolElement {
private:
	int time;
	
private:
	PoolElement(const gameutil::PoolElement&);
	const gameutil::PoolElement& operator=(const gameutil::PoolElement&);
	
public:
	explicit PoolElement(int);
	virtual ~PoolElement(void);
	
public:
	inline int getTime(void) const { return time; }
	inline void advanceTime(void) { time--; }
	
public:
	virtual void execute(void) = 0;
	virtual bool isActive(void) = 0;
};

#endif // ___POOL_ELEMENT_H