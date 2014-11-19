#ifndef ___ENEMY_FILE_ELEMENT_H
#define ___ENEMY_FILE_ELEMENT_H

#include <string>
#include "enemyDeclaration.h"

class enemyIO::EnemyFileElement {
private:
	int hp;
	bool canCollide_;
	std::string enemyName;
	std::string imageFileName;
	std::string initialStateString;
	std::string movePatternString;
	std::string bulletPatternString;
	std::string imagePatternString;
	std::string optionPatternString;

public:
	EnemyFileElement(std::string, std::string, int, bool, std::string, std::string, std::string, std::string, std::string);
	~EnemyFileElement(void);
	EnemyFileElement(const enemyIO::EnemyFileElement&);
	enemyIO::EnemyFileElement& operator=(const enemyIO::EnemyFileElement&);


public:
	inline const int getHp(void) const { return hp; }
	inline const bool canCollide(void) const { return canCollide_; }
	inline const std::string& getEnemyName(void) const { return enemyName; }
	inline const std::string& getImageFileName(void) const { return imageFileName; }
	inline const std::string& getInitialStateString(void) const { return initialStateString; }
	inline const std::string& getMovePatternString(void) const { return movePatternString; }
	inline const std::string& getBulletPatternString(void) const { return bulletPatternString; }
	inline const std::string& getImagePatternString(void) const { return imagePatternString; }
	inline const std::string& getOptionPatternString(void) const { return optionPatternString; }

	static int count;
	void dump(void);
};

#endif // ___ENEMY_FILE_ELEMENT_H
