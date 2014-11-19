#ifndef ___BULLET_FACTORY_H
#define ___BULLET_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "bullet.h"
#include "bulletFileElement.h"
#include "constantField.h"
#include "imageFactory.h"
#include "movePattern.h"
#include "movePatternFactory.h"

namespace factory {
	class BulletFactory;
}

class factory::BulletFactory {
private:
	BulletFactory(const factory::BulletFactory&);
	BulletFactory& operator=(const factory::BulletFactory&);
	
public:
	BulletFactory(void);
	~BulletFactory(void);
	
	bulletutil::Bullet* createBullet(const bulletIO::BulletFileElement&);

private:
	int countLine(std::string);
	void analyzeInitialState(std::string, bulletutil::Bullet*);
};

#endif // ___BULLET_FACTORY_H
