#include "labelFactory.h"

using std::count;
using std::replace;
using std::istringstream;
using std::string;
using factory::LabelFactory;
using labelutil::Label;
using labelutil::LabelMovePattern;
using labelIO::LabelFile;
using graphics::Image;
using graphics::ImageFactory;

LabelFactory::LabelFactory(void) {
}

LabelFactory::~LabelFactory(void) {
}

Label* LabelFactory::createLabel(const LabelFile& labelFile) {
    Image* image = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + labelFile.getImageFileName()).c_str());
    return createLabel(labelFile, image);
}

Label* LabelFactory::createLabel(const LabelFile& labelFile, Image* image) {
    LabelMovePattern* labelMovePattern = createLabelMovePattern(labelFile.getMovePatternString());
    
    string isStr = labelFile.getInitialStateString();

    assert(static_cast<int>(count(isStr.begin(), isStr.end(), ',')) == 5);
    
    replace(isStr.begin(), isStr.end(), ',', ' ');
    istringstream in(isStr);

    int x;
    int y;
    int z;
    double vr;
    double vtheta;
    double vphi;
        
    in >> x >> y >> z >> vr >> vtheta >> vphi;

    Label* label = new Label(x, y, z, vr, vtheta, vphi, image, labelMovePattern);
    
    return label;
}

LabelMovePattern* LabelFactory::createLabelMovePattern(string mpStr) {
    int line = static_cast<int>(count(mpStr.begin(), mpStr.end(), '\n'));
    int comma = static_cast<int>(count(mpStr.begin(), mpStr.end(), ','));
    
    assert(line*6 == comma);
    
    replace(mpStr.begin(), mpStr.end(), ',', ' ');
    istringstream in(mpStr);
    
    LabelMovePattern* labelMovePattern = new LabelMovePattern;
    for (int i = 0; i < line; i++) {
        double ar;
        double atheta;
        double aphi;
        double xangle;
        double yangle;
        double zangle;
        int time;
        
        in >> ar >> atheta >> aphi >> xangle >> yangle >> zangle >> time;
        labelMovePattern->addLabelMovePatternElement(ar, atheta, aphi, xangle, yangle, zangle, time);
    }

    return labelMovePattern;
}
