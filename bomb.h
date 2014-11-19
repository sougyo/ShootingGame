#ifndef ___BOMB_H
#define ___BOMB_H

#include <cmath>
#include "constantField.h"
#include "moveable.h"
#include "gameInformation.h"
#include "table.h"
#include "Image.h"
#include "ImageFactory.h"

namespace bombutil {
	class Bomb;
}

class bombutil::Bomb : public gameutil::Moveable {
public:
	static gamesystem::GameInformation* gameInformation;
	
private:
	int lock;
	int radius;
	graphics::Image* image;
	
private:
	Bomb(const bombutil::Bomb&);
	const bombutil::Bomb& operator=(const bombutil::Bomb&);

public:
	Bomb(void);
	~Bomb(void);
	
public:
	void fire(int, int);
	void move(void);
	void draw(void);
	inline int isEmpty(void) const { return gameInformation->getBomb() == 0; }
	inline int getRadius(void) const { return radius; }
};

#endif // ___BOMB_H
