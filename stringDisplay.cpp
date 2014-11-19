#include "stringDisplay.h"

using std::string;
using std::ostringstream;
using gamesystem::StringDisplay;
using graphics::Image;
using graphics::ImageFactory;

StringDisplay StringDisplay::singleton;

StringDisplay::StringDisplay(void) : identChar("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789__") {
    activeImages = new Image*[identChar.size()];
    inactiveImages = new Image*[identChar.size()];
    imageWidth = 20;
    imageHeight = 25;
}

StringDisplay::~StringDisplay(void) {
    delete[] activeImages;
    delete[] inactiveImages;
}

void StringDisplay::initialize(void) {
    ImageFactory* imageFactory = ImageFactory::getInstance();
    ostringstream out;
    out << "(" << imageWidth << "," << imageHeight << ").png";
    for (int i = 0; i < static_cast<int>(identChar.size()); i++) {
        string fileName1 = identChar[i] + static_cast<string>("1") + out.str();
        string fileName2 = identChar[i] + static_cast<string>("2") + out.str();
        
        activeImages[i] = imageFactory->createImage((gameutil::ALPHA_IMAGE_PATH + fileName1).c_str());
        inactiveImages[i] = imageFactory->createImage((gameutil::ALPHA_IMAGE_PATH + fileName2).c_str());
    }
}

Image* StringDisplay::getActiveImage(char c) {
    unsigned index = static_cast<unsigned>(identChar.find(c));
    if (index == identChar.npos)
        return 0;
    return activeImages[index];
}

Image* StringDisplay::getInactiveImage(char c) {
    unsigned index = static_cast<unsigned>(identChar.find(c));
    if (index == identChar.npos)
        return 0;
    return inactiveImages[index];
}

void StringDisplay::drawString(string str, int x, int y) {
    for (int i = 0; i < static_cast<int>(str.size()); i++) {
        assert(getActiveImage(str[i]));
        getActiveImage(str[i])->drawImage(0, x + i * imageWidth, y);
    }
}
