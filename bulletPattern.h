#ifndef ___BULLET_PATTERN_H
#define ___BULLET_PATTERN_H

#include <cassert>
#include <cstdlib>
#include <string>
#include <vector>
#include "bullet.h"
#include "bulletFactory.h"
#include "bulletFileElement.h"
#include "gamemath.h"

namespace bulletutil {
	class BulletPattern;
	struct BulletPatternElement;
}

struct bulletutil::BulletPatternElement {
	const bulletIO::BulletFileElement* bulletFileElement;
	double angle;
	int time;
	bool follow;
};

class bulletutil::BulletPattern {
public:
	enum Kind { Normal = 800000, Dynamic, Follow, Killed };
private:
	int currentTime;
	std::vector<bulletutil::BulletPatternElement> bulletPatternElements;
	std::vector<bulletutil::BulletPatternElement> killedBulletPatternElements;

private:
	BulletPattern(const bulletutil::BulletPattern&);
	bulletutil::BulletPattern& operator=(const bulletutil::BulletPattern&);
	
public:
	BulletPattern(void);
	~BulletPattern(void);
	
public:
	void addBulletPatternElement(const bulletIO::BulletFileElement*, double, int);
	void addKilledBulletFileElement(const bulletIO::BulletFileElement*, double);
	bulletutil::Bullet** createBulletArray(void);
	bulletutil::Bullet** createKilledBulletArray(void);
	inline int getBulletSize(void) const { return static_cast<int>(bulletPatternElements.size()); }
	inline int getKilledBulletSize(void) const { return static_cast<int>(killedBulletPatternElements.size()); }
	
	inline bool isFollow(int index) const { assert(index < static_cast<int>(bulletPatternElements.size())); return bulletPatternElements[index].follow; }
	inline bool isDynamic(int index) const { assert(index < static_cast<int>(bulletPatternElements.size())); return bulletPatternElements[index].angle == Dynamic; }
	
	bool checkIndex(int, int);
	
	inline int getCurrentTime(void) const { return currentTime; }
	void dump(void) const;

private:
	bulletutil::BulletPatternElement initializeBulletPatternElement(const bulletIO::BulletFileElement*, double, int, bool);
	
public:
	static int count;
};

#endif // ___BULLET_PATTERN_H