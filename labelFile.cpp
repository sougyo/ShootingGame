#include "labelFile.h"

using std::string;
using labelIO::LabelFile;

LabelFile::LabelFile(string imageFileName, string initialStateString, string movePatternString) {
    this->imageFileName = imageFileName;
    this->initialStateString = initialStateString;
    this->movePatternString = movePatternString;
}

LabelFile::~LabelFile(void) {
}
