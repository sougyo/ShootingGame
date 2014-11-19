#ifndef ___ENEMY_PATTERN_H
#define ___ENEMY_PATTERN_H

#include <cassert>
#include <vector>
#include "enemyDeclaration.h"
#include "enemyFile.h"
#include "enemyFileElement.h"
#include "enemyFactory.h"
#include "enemy.h"

struct enemyutil::EnemyPatternElement {
	const enemyIO::EnemyFileElement* enemyFileElement;
	int time;
};

class enemyutil::EnemyPattern {
private:
	int currentTime;
	const enemyIO::EnemyFile* enemyFile;
	std::vector<enemyutil::EnemyPatternElement> enemyPatternElements;
	
private:
	EnemyPattern(const enemyutil::EnemyPattern&);
	const enemyutil::EnemyPattern& operator=(const enemyutil::EnemyPattern&);
	
public:
	explicit EnemyPattern(const enemyIO::EnemyFile*);
	~EnemyPattern(void);
	
public:
	void addEnemyPatternElement(const enemyIO::EnemyFileElement*, int);
	enemyutil::Enemy** createEnemyArray(void);
	bool checkIndex(int, int);
	inline int getSize(void) const { return static_cast<int>(enemyPatternElements.size()); }
	
public:
	static int count; // デバッグ用
};

#endif // ___ENEMY_PATTERN_H