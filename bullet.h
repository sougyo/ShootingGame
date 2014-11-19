#ifndef ___BULLET_H
#define ___BULLET_H

#include <cassert>
#include "bomb.h"
#include "gamefwd.h"
#include "image.h"
#include "gameMath.h"
#include "movePattern.h"

namespace bulletutil {
	class Bullet;
}

#include "bulletElement.h"

class bulletutil::Bullet {
private:
	friend class bulletutil::BulletElement;
	
private:
	int maxSize;
	int size;
	bool isActive_;
	bool isBeam;
	int activeCount;
	int radius;
	graphics::Image* image;

private:
	bulletutil::BulletElement* bulletElements;
	gameutil::MovePattern* movePattern;

private:
	Bullet(const bulletutil::Bullet&);
	bulletutil::Bullet& operator=(const bulletutil::Bullet&);

public:
	Bullet(int, gameutil::MovePattern*, graphics::Image*, bool isBeam = false);
	~Bullet(void);

public:
	void addBulletElement(double, double, double, double, int);
	void fire(int, int);
	void move(void);
	void draw(void);
	void checkCollision(bombutil::Bomb*);
	void checkCollision(gamesystem::Fighter*);
	void rotate(double);
	void translate(double, double);
	void deleteExtraBulletElement(void);
	
	inline void kill(void) { isActive_ = false; }
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) const { return size; }
	inline int getActiveCount(void) const { return activeCount; }
	inline int getRadius(void) const { return radius; }
	
	bulletutil::BulletElement* getBulletElement(int);
	void dump(void); // デバッグ用
};

#endif // ___BULLET_H