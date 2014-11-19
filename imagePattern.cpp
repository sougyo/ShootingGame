#include "imagePattern.h"

using graphics::Image;
using gameutil::Images;
using gameutil::ImagePattern;
using gameutil::ImagePatternElement;

ImagePattern::ImagePattern(void) : currentTime(0) {
}

ImagePattern::~ImagePattern(void) {
    for (int i = 0; i < getSize(); i++)
        delete imagePatternElements[i];
}

void ImagePattern::addImagePatternElement(Images* images, int time) {
    assert(time);
    currentTime += time;
    imagePatternElements.push_back(new ImagePatternElement(images, currentTime));
}

Image* ImagePattern::getImage(int& index, int time) {
    assert(0 <= index && index < getSize());
    if (imagePatternElements[index]->getTime() == time && (index+1) != getSize())
        index++;
    
    return imagePatternElements[index]->getImage(time);
}
