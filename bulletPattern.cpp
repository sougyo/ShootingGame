#include "bulletPattern.h"

using std::string;
using bulletutil::Bullet;
using bulletutil::BulletPattern;
using bulletutil::BulletPatternElement;
using bulletIO::BulletFileElement;
using factory::BulletFactory;

int BulletPattern::count = 0;

BulletPattern::BulletPattern(void) : currentTime(0) {
	count++;
}

BulletPattern::~BulletPattern(void) {
	count--;
}

void BulletPattern::addBulletPatternElement(const BulletFileElement* bfe, double angle, int time) {
	if (time == Follow)
		bulletPatternElements.push_back(
				initializeBulletPatternElement(bfe, angle, ++currentTime, true));
	else {
		currentTime += time;
		bulletPatternElements.push_back(
				initializeBulletPatternElement(bfe, angle, currentTime, false));
	}
}

void BulletPattern::addKilledBulletFileElement(const BulletFileElement* bfe, double angle) {
	killedBulletPatternElements.push_back(
			initializeBulletPatternElement(bfe, angle, 0, false));
}

bulletutil::Bullet** BulletPattern::createBulletArray(void) {
	BulletFactory bulletFactory;
	if (bulletPatternElements.size() == 0)
		return 0;
	Bullet** bullets = new Bullet*[bulletPatternElements.size()];
	for (int i = 0; i < static_cast<int>(bulletPatternElements.size()); i++) {
		bullets[i] = bulletFactory.createBullet(*bulletPatternElements[i].bulletFileElement);
		if (!isDynamic(i))
			bullets[i]->rotate(bulletPatternElements[i].angle);
	}
	return bullets;
}

bulletutil::Bullet** BulletPattern::createKilledBulletArray(void) {
	BulletFactory bulletFactory;
	if (killedBulletPatternElements.size() == 0)
		return 0;
	Bullet** bullets = new Bullet*[killedBulletPatternElements.size()];
	for (int i = 0; i < static_cast<int>(killedBulletPatternElements.size()); i++) {
		bullets[i] = bulletFactory.createBullet(*killedBulletPatternElements[i].bulletFileElement);
		bullets[i]->rotate(killedBulletPatternElements[i].angle);
	}
		
	return bullets;
}

BulletPatternElement BulletPattern::initializeBulletPatternElement(const bulletIO::BulletFileElement* bfe, double angle, int time, bool isFollow) {
	struct BulletPatternElement bpe;
	bpe.bulletFileElement = bfe;
	bpe.angle = (angle == Dynamic) ? Dynamic : gamemath::toRadian(angle);
	bpe.time = time;
	bpe.follow = isFollow;
	return bpe;
}

bool BulletPattern::checkIndex(int bulletPatternIndex, int time) {
	assert(bulletPatternIndex >= 0 && bulletPatternIndex <= getBulletSize());
	if (bulletPatternIndex == getBulletSize())
		return false;
	
	if (time == bulletPatternElements[bulletPatternIndex].time)
		return true;
	
	return false;
}

#include <iostream>
void BulletPattern::dump(void) const {
	std::cout << "\n--BulletPatternDumpStart" << std::endl;
	std::cout << "name\tangle\ttime\tfollow" << std::endl;
	for (int i = 0; i < static_cast<int>(bulletPatternElements.size()); i++) {
		std::cout << bulletPatternElements[i].bulletFileElement->getBulletName() << '\t'
				  << bulletPatternElements[i].angle << '\t'
				  << bulletPatternElements[i].time << '\t'
				  << bulletPatternElements[i].follow << std::endl;
	}
	std::cout << "killedBullet is " << static_cast<int>(killedBulletPatternElements.size()) << std::endl;
	for (int i = 0; i < static_cast<int>(killedBulletPatternElements.size()); i++) {
		std::cout << killedBulletPatternElements[i].bulletFileElement->getBulletName() << '\t'
				  << killedBulletPatternElements[i].angle << '\t'
				  << killedBulletPatternElements[i].time << '\t'
				  << killedBulletPatternElements[i].follow << std::endl;
	}
	std::cout << "--BulletPatternDumpEnd\n" << std::endl;
}
