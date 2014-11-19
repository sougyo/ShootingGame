#ifndef ___BOSS_H
#define ___BOSS_H

#include <vector>
#include "bossElement.h"
#include "bullet.h"
#include "enemy.h"
#include "gauge.h"
#include "Image.h"
#include "table.h"

namespace bossutil {
	class Boss;
}

class bossutil::Boss {
public:
	static gameutil::Table<bulletutil::Bullet>* bulletTable;
	static gameutil::Table<enemyutil::Enemy>* enemyTable;
	
private:
	bool isActive_;
	int index;
	graphics::Image* bossNameImage;
	graphics::Image* bossSubNameImage;
	gameutil::Gauge gauge;
	
private:
	std::vector<bossutil::BossElement*> bossElements;
	
private:
	Boss(const bossutil::Boss&);
	const bossutil::Boss& operator=(const bossutil::Boss&);
	
public:
	Boss(graphics::Image*, graphics::Image*);
	~Boss(void);
	
public:
	void fire(int, int);
	void move(void);
	void draw(void);
	void addBossElement(int, graphics::Image*, enemyutil::Enemy*);
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) const { return static_cast<int>(bossElements.size()); }
};

#endif // ___BOSS_H
