#ifndef ___ENEMY_FILE_READER_H
#define ___ENEMY_FILE_READER_H

#include <cassert>
#include <cstdlib>
#include <string>
#include "enemyDeclaration.h"
#include "bulletFile.h"
#include "bulletFileReader.h"
#include "enemyFile.h"
#include "enemyFileElement.h"
#include "constantField.h"
#include "fileReader.h"

class enemyIO::EnemyFileReader : public gameutil::FileReader {
private:
	EnemyFileReader(const enemyIO::EnemyFileReader&);
	enemyIO::EnemyFileReader& operator=(const enemyIO::EnemyFileReader&);

private:
	explicit EnemyFileReader(const char*);
	
public:
	EnemyFileReader(const char*, const char*);
	~EnemyFileReader(void);
	
public:
	enemyIO::EnemyFile* createEnemyFile(void);
	
private:
	bulletIO::BulletFile* analyzeBulletFile(void);
	int analyzeHp(void);
	bool analyzeCanCollision(void);
	std::string analyzeEnemyName(std::string);
	std::string analyzeImageFileName(void);
	std::string analyzeInitialStateString(void);
	std::string analyzeMovePatternString(void);
	std::string analyzeBulletPatternString(void);
	std::string analyzeImagePatternString(void);
	std::string analyzeOptionPatternString(void);
	
	void ignoreMemoString(void);
};


#endif // ___ENEMY_FILE_READER_H