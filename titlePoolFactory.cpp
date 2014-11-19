#include "titlePoolFactory.h"

using std::count;
using std::istringstream;
using std::replace;
using std::string;
using factory::TitlePoolFactory;
using factory::LabelFactory;
using graphics::Image;
using graphics::ImageFactory;
using labelutil::Label;
using labelIO::LabelFile;
using labelIO::LabelFileReader;
using titleutil::TitlePool;
using titleutil::TitlePoolElement;

TitlePoolFactory::TitlePoolFactory(void) {
}

TitlePoolFactory::~TitlePoolFactory(void) {
}

TitlePool* TitlePoolFactory::createTitlePool(string titleStr) {
	TitlePool* titlePool = new TitlePool;
	
	int line = static_cast<int>(count(titleStr.begin(), titleStr.end(), '\n'));
	replace(titleStr.begin(), titleStr.end(), ':', ' ');
	assert(line*4 == static_cast<int>(count(titleStr.begin(), titleStr.end(), ' ')));
	istringstream in(titleStr);
	
	string fileName;
	int x;
	int y;
	string imageName;
	int time;
	for (int i = 0; i < line; i++) {
		in >> fileName;
		in >> x;
		in >> y;
		in >> imageName;
		in >> time;
		titlePool->addPoolElement(new TitlePoolElement(createLabel(fileName, imageName), x, y, time));		
	}
	return titlePool;
}

Label* TitlePoolFactory::createLabel(string fileName, string imageName) {
	LabelFileReader labelFileReader(gameutil::DATA_PATH.c_str(), fileName.c_str());
	LabelFile* labelFile = labelFileReader.createLabelFile();
	LabelFactory labelFactory;
	Label* label;
	if (imageName == "null")
		label = labelFactory.createLabel(*labelFile);
	else {
		Image* image = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + imageName).c_str());
		label = labelFactory.createLabel(*labelFile, image);
	}
	
	
	delete labelFile;
	
	return label;
}