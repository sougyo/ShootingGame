#include "imagePatternFactory.h"

using std::count;
using std::istringstream;
using std::string;
using std::vector;
using factory::ImagePatternFactory;
using gameutil::ImagePattern;
using gameutil::ImagePatternElement;
using gameutil::Images;
using graphics::Image;
using graphics::ImageFactory;

ImagePatternFactory::ImagePatternFactory(void) {
}

ImagePatternFactory::~ImagePatternFactory(void) {
}

ImagePattern* ImagePatternFactory::createImagePattern(string imgStr) {
    if (imgStr == "")
        return 0;
    
    int line = static_cast<int>(count(imgStr.begin(), imgStr.end(), '\n'));
    assert(line);
    
    ImagePattern* imagePattern = new ImagePattern;
    istringstream in(imgStr);
    char temp[2000];
    for (int i = 0; i < line; i++) {
        in.getline(temp, 2000);
        addImagePatternElement(*imagePattern, temp);
    }
    return imagePattern;
}

void ImagePatternFactory::addImagePatternElement(gameutil::ImagePattern& imagePattern, string imgsStr) {
    int imageNumber = static_cast<int>(count(imgsStr.begin(), imgsStr.end(), ' ')) - 1;
    assert(imageNumber > 0);
    
    istringstream in(imgsStr);
    vector<string> imageFileNames;
    string temp;
    for (int i = 0; i < imageNumber; i++) {
        in >> temp;
        imageFileNames.push_back(temp);
    }
    
    int interval, time;
    in >> interval >> time;
        
    Images* images = new Images(interval);
    for (int i = 0; i < imageNumber; i++) {
        string imageFileName = gameutil::IMAGE_PATH + imageFileNames[i];
        Image* image = ImageFactory::getInstance()->createImage(imageFileName.c_str());
        images->addImage(image);
    }
    
    imagePattern.addImagePatternElement(images, time);
}
