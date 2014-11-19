#include "gameFunctions.h"

bool gameutil::checkCollision(gameutil::Moveable* moveable1, gameutil::Moveable* moveable2, int distance) {
	if (!moveable1->isAppearance() || !moveable2->isAppearance())
		return false;
	double tx = moveable1->getX() - moveable2->getX();
	double ty = moveable1->getY() - moveable2->getY();
	return (tx*tx + ty*ty) < static_cast<double>(distance*distance);
}

bool gameutil::checkCollision(gameutil::Moveable* moveable, gamesystem::Fighter* fighter, int distance) {
	if (!moveable->isAppearance())
		return false;
	double tx = moveable->getX() - fighter->getX();
	double ty = moveable->getY() - fighter->getY();
	return (tx*tx + ty*ty) < static_cast<double>(distance*distance);
}

void gameutil::drawNowLoadingImage(void) {
	graphics::ImageFactory::getInstance()->createImage((gameutil::STATE_IMAGE_PATH + "loadinglabel(200,40).png").c_str())->drawImage(0,530,450);
}