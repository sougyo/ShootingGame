#ifndef ___IMAGE_PATTERN_FACTORY_H
#define ___IMAGE_PATTERN_FACTORY_H

#include <algorithm>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include "constantField.h"
#include "Image.h"
#include "ImageFactory.h"
#include "images.h"
#include "imagePattern.h"

namespace factory {
	class ImagePatternFactory;
}

class factory::ImagePatternFactory {
private:
	ImagePatternFactory(const factory::ImagePatternFactory&);
	const factory::ImagePatternFactory& operator=(const factory::ImagePatternFactory&);
	
public:
	ImagePatternFactory(void);
	~ImagePatternFactory(void);
	
public:
	gameutil::ImagePattern* createImagePattern(std::string);
	
private:
	void addImagePatternElement(gameutil::ImagePattern&, std::string);
};

#endif //___IMAGE_PATTERN_FACTORY_H
