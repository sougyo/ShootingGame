#include "missileSetFactory.h"

using std::count;
using std::istringstream;
using std::replace;
using std::string;
using gameutil::MovePattern;
using missileutil::Missile;
using missileutil::MissileSet;
using missileIO::MissileFile;
using missileIO::MissileFileElement;
using factory::MissileSetFactory;
using factory::MovePatternFactory;

MissileSetFactory::MissileSetFactory(void) {
}

MissileSetFactory::~MissileSetFactory(void) {
}
	
MissileSet* MissileSetFactory::createMissileSet(const MissileFile* missileFile) {
	MissileSet* missileSet = new MissileSet(missileFile->getTotalTime());
	for (int i = 0; i < missileFile->getSize(); i++) {
		const MissileFileElement* missileFileElement = missileFile->getMissileFileElement(i);
		Missile* missile = createMissile(missileFileElement, missileFile->getTotalTime());
		missileSet->addMissile(missile);
	}
	return missileSet;
}

Missile* MissileSetFactory::createMissile(const MissileFileElement* missileFileElement, int totalTime) {
	int interval = missileFileElement->getInterval();
	MovePatternFactory movePatternFactory;
	MovePattern* movePattern = 
		movePatternFactory.createMovePattern(missileFileElement->getMovePatternString());
	graphics::Image* image = 
		graphics::ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + missileFileElement->getImageFileName()).c_str());
	int size = getMissileSize(missileFileElement->getInitialStateString(), totalTime, interval);
	Missile* missile = new Missile(size, movePattern, image);
	analyzeInitialState(missileFileElement->getInitialStateString(), missile, totalTime, interval);
	return missile;
}

void MissileSetFactory::analyzeInitialState(string isStr, Missile* missile, int totalTime, int interval) {
	int line = static_cast<int>(count(isStr.begin(), isStr.end(), '\n'));
	int comma = static_cast<int>(count(isStr.begin(), isStr.end(), ','));
	
	assert(line*3 == comma);
	
	replace(isStr.begin(), isStr.end(), ',', ' ');
	
	for (int time = 0; time < totalTime; time += interval) {
		istringstream in(isStr);
		for (int i = 0; i < line; i++) {
			double x;
			double y;
			double vr;
			double vtheta;
			
			in >> x >> y >> vr >> vtheta;
			missile->addMissileElement(x, y, vr, vtheta, time);
		}
	}
}

int MissileSetFactory::getMissileSize(string isStr, int totalTime, int interval) {
	int oneFrameSize = static_cast<int>(count(isStr.begin(), isStr.end(), '\n'));
	int frame = totalTime / interval;
	if (totalTime % interval != 0)
		frame++;
	return oneFrameSize * frame;
}