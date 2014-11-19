#ifndef ___IMAGE_PATTERN_H
#define ___IMAGE_PATTERN_H

#include <cassert>
#include <vector>
#include "Image.h"
#include "images.h"
#include "imagePatternElement.h"

namespace gameutil {
    class ImagePattern;
}

class gameutil::ImagePattern {
private:
    int currentTime;
    std::vector<gameutil::ImagePatternElement*> imagePatternElements;
    
private:
    ImagePattern(const gameutil::ImagePattern&);
    const gameutil::ImagePattern& operator=(const gameutil::ImagePattern&);
    
public:
    ImagePattern(void);
    ~ImagePattern(void);
    
public:
    void addImagePatternElement(gameutil::Images*, int);
    graphics::Image* getImage(int&, int);
    inline int getSize(void) const { return static_cast<int>(imagePatternElements.size()); }
};


#endif // ___IMAGE_PATTERN_H
