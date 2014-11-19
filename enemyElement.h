#ifndef ___ENEMY_ELEMENT_H
#define ___ENEMY_ELEMENT_H

#include "gamefwd.h"
#include "bomb.h"
#include "enemyDeclaration.h"
#include "bullet.h"
#include "bulletElement.h"
#include "item.h"
#include "fighter.h"
#include "moveable.h"
#include "missileElement.h"
#include "enemy.h"
#include "effectPool.h"
#include "gameFunctions.h"
#include "gameInformation.h"
#include "DirectSound.h"

class enemyutil::EnemyElement : public gameutil::Moveable {
private:
	enemyutil::Enemy* owner;
	
public:
	static effectutil::EffectPool* effectPool;
	static gamesystem::GameInformation* gameInformation;
	
private:
	int delay;
	int hp;
	int bulletPatternIndex;
	int enemyPatternIndex;
	int imagePatternIndex;
	int score;
	bulletutil::Bullet** bullets;
	bulletutil::Bullet** killedBullets;
	enemyutil::Enemy** enemys;
	itemutil::Item* item;

private:
	EnemyElement(const enemyutil::EnemyElement&);
	const enemyutil::EnemyElement& operator=(const enemyutil::EnemyElement&);
	
public:
	EnemyElement(enemyutil::Enemy*, double, double, double, double, int, int, int, bulletutil::Bullet**, bulletutil::Bullet**, enemyutil::Enemy**, itemutil::Item*);
	~EnemyElement(void);

public:
	void fire(int, int);
	void move(void);
	void draw(void);
	void checkCollision(bombutil::Bomb*, int);
	void checkCollision(gamesystem::Fighter*, int);
	void checkCollision(missileutil::MissileElement*, int);
	
	bulletutil::Bullet* getBullet(int);
	bulletutil::Bullet* getKilledBullet(int);

	inline int getHp(void) const { return hp; }
	int getScore(void);
	
	static int count;
	void dump(void);
	void dumpBullets(void);

private:
	int getBulletSize(void);
	int getKilledBulletSize(void);
	int getEnemySize(void);
	void toInactive(void);

private:
	void followProcess(void);
	void fireBulletProcess(void);
	void fireEnemyProcess(void);
	void killedProcess(void);
	void deleteFollowBullets(void);
};

#endif // ___ENEMY_ELEMENT_H
