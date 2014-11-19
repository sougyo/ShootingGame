#ifndef ___IMAGES_H
#define ___IMAGES_H

#include <cassert>
#include <vector>
#include "Image.h"

namespace gameutil {
	class Images;
}

class gameutil::Images {
private:
	int interval;
	std::vector<graphics::Image*> images;
	
private:
	Images(const gameutil::Images&);
	const gameutil::Images& operator=(const gameutil::Images&);
	
public:
	explicit Images(int);
	~Images(void);
	
public:
	void addImage(graphics::Image*);
	graphics::Image* getImage(int time) { return images[ (time / interval) % getSize() ]; }
	inline int getSize(void) const { return static_cast<int>(images.size()); }
};

#endif // ___IMAGES_H
