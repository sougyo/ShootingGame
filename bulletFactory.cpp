#include "bulletFactory.h"

using std::count;
using std::replace;
using std::string;
using std::istringstream;
using factory::BulletFactory;
using factory::MovePatternFactory;
using gameutil::MovePattern;
using bulletutil::Bullet;
using bulletIO::BulletFileElement;

BulletFactory::BulletFactory(void) {
}

BulletFactory::~BulletFactory(void) {
}

Bullet* BulletFactory::createBullet(const BulletFileElement& bfe) {
	MovePatternFactory mpFactory;
	MovePattern* mp = mpFactory.createMovePattern(bfe.getMovePatternString());
	int size = countLine(bfe.getInitialStateString());
	graphics::Image* image = graphics::ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + bfe.getImageFileName()).c_str());

	Bullet* bullet = new Bullet(size, mp, image);
	analyzeInitialState(bfe.getInitialStateString(), bullet);
	
	return bullet;
}

int BulletFactory::countLine(string str) {
	return static_cast<int>(count(str.begin(), str.end(), '\n'));
}

void BulletFactory::analyzeInitialState(string isStr, Bullet* bullet) {
	int line = static_cast<int>(count(isStr.begin(), isStr.end(), '\n'));
	int comma = static_cast<int>(count(isStr.begin(), isStr.end(), ','));
	
	assert(line*4 == comma);
	
	replace(isStr.begin(), isStr.end(), ',', ' ');
	istringstream in(isStr);
	
	for (int i = 0; i < line; i++) {
		double x;
		double y;
		double vr;
		double vtheta;
		unsigned time;
		
		in >> x >> y >> vr >> vtheta >> time;
		bullet->addBulletElement(x, y, vr, vtheta, time);
	}
}
