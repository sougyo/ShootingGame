#ifndef ___BULLET_ELEMENT_H
#define ___BULLET_ELEMENT_H

#include <cmath>
#include "gamefwd.h"
#include "bomb.h"
#include "constantField.h"
#include "effectPool.h"
#include "moveable.h"
#include "gameFunctions.h"
#include "gameInformation.h"

namespace bulletutil {
	class BulletElement;
}

#include "bullet.h"

class bulletutil::BulletElement : public gameutil::Moveable {
public:
	static effectutil::EffectPool* effectPool;
	static gamesystem::GameInformation* gameInformation;
	
private:
	bulletutil::Bullet* owner;
	bool isGraze;

public:
	BulletElement(void);
	BulletElement(bulletutil::Bullet*, double, double, double, double, int);
	~BulletElement(void);
	BulletElement(const bulletutil::BulletElement&);
	bulletutil::BulletElement& operator=(const bulletutil::BulletElement&);
	
public:
	void fire(int, int);
	void move(void);
	void draw(void);
	void checkCollision(bombutil::Bomb*, int);
	void checkCollision(gamesystem::Fighter*, int);
	void rotate(double);
	void deleteExtraBulletElement(void);
	
	static int count; // デバッグ用
	void dump(void); // デバッグ用
	
private:
	void toInactive(void);
};

#endif // ___BULLET_ELEMENT_H