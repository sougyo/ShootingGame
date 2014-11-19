#ifndef ___IMAGE_PATTERN_ELEMENT_H
#define ___IMAGE_PATTERN_ELEMENT_H

#include "Image.h"
#include "images.h"

namespace gameutil {
	class ImagePatternElement;
}

class gameutil::ImagePatternElement {
private:
	gameutil::Images* images;
	int time;
	
private:
	ImagePatternElement(const gameutil::ImagePatternElement&);
	const gameutil::ImagePatternElement& operator=(const gameutil::ImagePatternElement&);
	
public:
	ImagePatternElement(gameutil::Images*, int);
	~ImagePatternElement(void);
	
public:
	inline graphics::Image* getImage(int time) const { return images->getImage(time); }
	inline int getTime(void) const { return time; }
};

#endif // ___IMAGE_PATTERN_ELEMENT_H
