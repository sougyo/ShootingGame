#ifndef ___BOSS_FILE_H
#define ___BOSS_FILE_H

#include <cassert>
#include <string>
#include <vector>
#include "bossFileElement.h"
#include "enemyFile.h"

namespace bossIO {
	class BossFile;
}

class bossIO::BossFile {
private:
	std::string bossNameImageString;
	std::string bossSubNameImageString;
	enemyIO::EnemyFile* enemyFile;
	std::vector<bossIO::BossFileElement*> bossFileElements;
	
private:
	BossFile(const bossIO::BossFile&);
	const bossIO::BossFile& operator=(const bossIO::BossFile&);
	
public:
	BossFile(std::string, std::string, enemyIO::EnemyFile*);
	~BossFile(void);
	
public:
	void addBossFileElement(bossIO::BossFileElement*);
	const bossIO::BossFileElement* getBossFileElement(int) const;
	
	enemyIO::EnemyFile* getEnemyFile(void) const { return enemyFile; }
	inline std::string getBossNameImageString(void) const { return bossNameImageString; }
	inline std::string getBossSubNameImageString(void) const { return bossSubNameImageString; }
	inline int getSize(void) const { return static_cast<int>(bossFileElements.size()); }
};

#endif // ___BOSS_FILE_H