#ifndef ___ENEMY_H
#define ___ENEMY_H

#include <cassert>
#include "gamefwd.h"
#include "enemyDeclaration.h"
#include "bullet.h"
#include "bulletPattern.h"
#include "gameMath.h"
#include "movePattern.h"
#include "image.h"
#include "item.h"
#include "table.h"
#include "enemyPattern.h"
#include "enemyElement.h"
#include "fighter.h"
#include "imagePattern.h"
#include "missile.h"

class enemyutil::Enemy {
private:
	friend class enemyutil::EnemyElement;
	
public:
	static gameutil::Table<bulletutil::Bullet>* bulletTable;
	static gameutil::Table<enemyutil::Enemy>* enemyTable;
	static gameutil::Table<itemutil::Item>* itemTable;
	
public:
	static gameutil::Table<enemyutil::Enemy>* getEnemyTable(void) { return enemyTable; }

private:
	int maxSize;
	int size;
	bool canCollide;
	int hp;
	bool isActive_;
	int activeCount;
	int radius;
	gameutil::MovePattern* movePattern;
	bulletutil::BulletPattern* bulletPattern;
	enemyutil::EnemyPattern* enemyPattern;
	gameutil::ImagePattern* imagePattern;
	enemyutil::EnemyElement** enemyElements;
	graphics::Image* image;
	
private:
	Enemy(const enemyutil::Enemy&);
	const enemyutil::Enemy& operator=(const enemyutil::Enemy&);

public:
	Enemy(int, int, bool, gameutil::MovePattern*, bulletutil::BulletPattern*, enemyutil::EnemyPattern*, gameutil::ImagePattern*, graphics::Image*);
	~Enemy(void);
	
public:
	void addEnemyElement(double, double, double, double, int, int, double, itemutil::Item*);
	void fire(int, int);
	void move(void);
	void draw(void);
	void checkCollision(bombutil::Bomb*);
	void checkCollision(gamesystem::Fighter*);
	void checkCollision(missileutil::Missile*);
	
	inline void kill(void) { isActive_ = false; }
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) const { return size; }
	inline int getRadius(void) const { return radius; }
	int getHp(int);
	int getScore(void);
	
	enemyutil::EnemyElement* getEnemyElement(int);
	
	void dump(void);

private:
	void rotateBullets(bulletutil::Bullet**, int, double);
};

#endif // ___ENEMY_H
