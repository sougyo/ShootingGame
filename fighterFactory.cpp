#include "fighterFactory.h"

using factory::FighterFactory;
using gamesystem::Fighter;
using gamesystemIO::FighterFile;
using graphics::Image;
using graphics::ImageFactory;
using missileutil::MissileSetController;
using missileIO::MissileFile;
using missileIO::MissileFileReader;

FighterFactory::FighterFactory(void) {
}

FighterFactory::~FighterFactory(void) {
}

Fighter* FighterFactory::createFighter(const FighterFile& fighterFile) {
	int radius = fighterFile.getRadius();
	double highSpeed = fighterFile.getHighSpeed();
	double slowSpeed = fighterFile.getSlowSpeed();

	Image* image = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + fighterFile.getImageFileName()).c_str());
	MissileFileReader missileFileReader(gameutil::DATA_PATH.c_str(), fighterFile.getMissileFileName().c_str());
	MissileFile* missileFile = missileFileReader.createMissileFile();
	MissileSetController* missileSetController = new MissileSetController(missileFile, 3);
	
	Fighter* fighter = new Fighter(radius, highSpeed, slowSpeed, image, missileSetController);
	delete missileFile;

	return fighter;
}
