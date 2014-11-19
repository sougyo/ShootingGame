#ifndef ___BOSS_POOL_ELEMENT_H
#define ___BOSS_POOL_ELEMENT_H

#include "boss.h"
#include "poolElement.h"
#include "table.h"

namespace bossutil {
	class BossPoolElement;
}

class bossutil::BossPoolElement : public gameutil::PoolElement {
public:
	static gameutil::Table<bossutil::Boss>* bossTable;
	
private:
	bossutil::Boss* boss;
	
private:
	BossPoolElement(const bossutil::BossPoolElement&);
	const bossutil::BossPoolElement& operator=(const bossutil::BossPoolElement&);
	
public:
	BossPoolElement(bossutil::Boss*, int);
	~BossPoolElement(void);
	
public:
	void execute(void);
	bool isActive(void);
};

#endif // ___BOSS_POOL_ELEMENT_H