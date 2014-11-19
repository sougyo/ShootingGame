#include "images.h"

using gameutil::Images;
using graphics::Image;

Images::Images(int interval) {
    this->interval = interval;
}

Images::~Images(void) {
}

void Images::addImage(Image* image) {
    images.push_back(image);
}
