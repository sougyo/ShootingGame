#ifndef ___ENEMY_FACTORY_H
#define ___ENEMY_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "enemyDeclaration.h"
#include "bulletPattern.h"
#include "bulletPatternFactory.h"
#include "imagePattern.h"
#include "imagePatternFactory.h"
#include "item.h"
#include "itemFactory.h"
#include "movePattern.h"
#include "movePatternFactory.h"
#include "enemy.h"
#include "enemyPattern.h"
#include "enemyPatternFactory.h"
#include "enemyFile.h"
#include "enemyFileElement.h"

class factory::EnemyFactory {
private:
	EnemyFactory(const factory::EnemyFactory&);
	factory::EnemyFactory& operator=(const factory::EnemyFactory&);
	
public:
	EnemyFactory(void);
	~EnemyFactory(void);

public:
	enemyutil::Enemy* createEnemy(const enemyIO::EnemyFile*, const enemyIO::EnemyFileElement&);

private:
	int countLine(std::string);
	void analyzeInitialState(std::string, enemyutil::Enemy*);
};

#endif // ___ENEMY_FACTORY_H
