#include "imagePatternElement.h"

using gameutil::ImagePatternElement;
using gameutil::Images;

ImagePatternElement::ImagePatternElement(Images* images, int time) {
    this->images = images;
    this->time = time;
}

ImagePatternElement::~ImagePatternElement(void) {
    delete images;
}
