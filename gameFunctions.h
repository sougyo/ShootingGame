#ifndef ___GAME_FUNCTIONS_H
#define ___GAME_FUNCTIONS_H

#include <string>
#include "gamefwd.h"
#include "moveable.h"
#include "fighter.h"
#include "Image.h"
#include "ImageFactory.h"

namespace gameutil {
	bool checkCollision(gameutil::Moveable*, gameutil::Moveable*, int);
	bool checkCollision(gameutil::Moveable*, gamesystem::Fighter*, int);
	void drawNowLoadingImage(void);
}

#endif // ___GAME_FUNCTIONS_H
