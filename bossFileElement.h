#ifndef ___BOSS_FILE_ELEMENT_H
#define ___BOSS_FILE_ELEMENT_H

#include <string>

namespace bossIO {
	class BossFileElement;
}

class bossIO::BossFileElement {
private:
	int limit;
	std::string techniqueImageFileName;
	std::string enemyName;
	
private:
	BossFileElement(const bossIO::BossFileElement&);
	const bossIO::BossFileElement& operator=(const bossIO::BossFileElement&);
	
public:
	BossFileElement(int, std::string, std::string);
	~BossFileElement(void);
	
public:
	inline int getLimit(void) const { return limit; }
	inline const std::string& getTechniqueImageFileName(void) const { return techniqueImageFileName; }
	inline const std::string& getEnemyName(void) const { return enemyName; }
};

#endif // ___BOSS_FILE_ELEMENT_H
