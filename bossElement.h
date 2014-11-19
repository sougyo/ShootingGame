#ifndef ___BOSS_ELEMENT_H
#define ___BOSS_ELEMENT_H

#include "Image.h"
#include "enemy.h"
#include "numberDisplay.h"
#include "table.h"

namespace bossutil {
	class BossElement;
}

class bossutil::BossElement {
public:
	static gameutil::Table<enemyutil::Enemy>* enemyTable;
	static gamesystem::GameInformation* gameInformation;
	
private:
	bool isActive_;
	int limit;
	graphics::Image* techniqueImage;
	enemyutil::Enemy* enemy;
	gamesystem::NumberDisplay numberDisplay;
	
private:
	BossElement(const bossutil::BossElement&);
	const bossutil::BossElement& operator=(const bossutil::BossElement&);
	
public:
	BossElement(int, graphics::Image*, enemyutil::Enemy*);
	~BossElement(void);
	
public:
	void fire(void);
	void move(void);
	void draw(void);
	inline bool isActive(void) const { return isActive_; }
	inline int getHp(void) const { return enemy->getHp(0); }
};

#endif // BOSS_ELEMENT_H