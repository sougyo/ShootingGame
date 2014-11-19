#ifndef ___ENEMY_PATTERN_FACTORY_H
#define ___ENEMY_PATTERN_FACTORY_H

#include <algorithm>
#include <string>
#include <sstream>
#include "enemyDeclaration.h"
#include "enemyFileElement.h"
#include "enemyPattern.h"
#include "enemyFile.h"

class factory::EnemyPatternFactory {
private:
	const enemyIO::EnemyFile* enemyFile;
	
private:
	EnemyPatternFactory(const factory::EnemyPatternFactory&);
	const factory::EnemyPatternFactory& operator=(const factory::EnemyPatternFactory&);
	
public:
	explicit EnemyPatternFactory(const enemyIO::EnemyFile*);
	~EnemyPatternFactory(void);
	
public:
	enemyutil::EnemyPattern* createEnemyPattern(std::string);
};

#endif // ___ENEMY_PATTERN_FACTORY_H