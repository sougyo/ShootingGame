#ifndef ___MISSILE_H
#define ___MISSILE_H

#include <cassert>
#include "missileDeclaration.h"
#include "image.h"
#include "gameMath.h"
#include "movePattern.h"
#include "missileElement.h"

class missileutil::Missile {
private:
	friend class missileutil::MissileElement;

private:
	int maxSize;
	int size;
	int activeCount;
	bool isActive_;
	missileutil::MissileElement** missileElements;
	gameutil::MovePattern* movePattern;
	graphics::Image* image;
	
private:
	Missile(const missileutil::Missile&);
	const missileutil::Missile& operator=(const missileutil::Missile&);
	
public:
	Missile(int, gameutil::MovePattern*, graphics::Image*);
	~Missile(void);
	
public:
	void addMissileElement(double, double, double, double, int);
	void fire(int, int);
	void move(void);
	void draw(void);
	missileutil::MissileElement* getMissileElement(int);
	inline int getRadius(void) const { return image->getRadius(); }
	inline bool isActive(void) const { return isActive_; }
	inline int getMaxSize(void) const { return maxSize; }
	inline int getSize(void) const { return size; }
};

#endif // ___MISSILE_H
