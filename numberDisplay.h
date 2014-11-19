#ifndef ___NUMBER_DISPLAY_H
#define ___NUMBER_DISPLAY_H

#include <cassert>
#include "constantField.h"
#include "image.h"
#include "imageFactory.h"

namespace gamesystem {
	class NumberDisplay;
}

class gamesystem::NumberDisplay {
private:
	int digit;
	int x;
	int y;
	
private:
	graphics::Image* zero;
	graphics::Image* one;
	graphics::Image* two;
	graphics::Image* three;
	graphics::Image* four;
	graphics::Image* five;
	graphics::Image* six;
	graphics::Image* seven;
	graphics::Image* eight;
	graphics::Image* nine;
	
private:
	NumberDisplay(const gamesystem::NumberDisplay&);
	const gamesystem::NumberDisplay& operator=(const gamesystem::NumberDisplay&);
	
public:
	NumberDisplay(int, int, int);
	~NumberDisplay(void);

public:
	void draw(int);
	inline int getX(void) const { return x; }
	inline int getY(void) const { return y; }
};

#endif // ___NUMBER_DISPLAY_H