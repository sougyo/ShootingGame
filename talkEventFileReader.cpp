#include "talkEventFileReader.h"

using std::string;
using talkeventutil::TalkEvent;
using talkeventutil::TalkEventFileReader;
using graphics::Image;
using graphics::ImageFactory;

TalkEventFileReader::TalkEventFileReader(const char* str1, const char* str2) : gameutil::FileReader(str1, str2) {
}

TalkEventFileReader::~TalkEventFileReader(void) {
}

TalkEvent* TalkEventFileReader::createTalkEvent(void) {
	ImageFactory* imageFactory = ImageFactory::getInstance();
	
	string leftActiveImageFileName = readLine();
	string leftInactiveImageFileName = readLine();
	string rightActiveImageFileName = readLine();
	string rightInactiveImageFileName = readLine();
	
	Image* left1Img  = imageFactory->createImage((gameutil::IMAGE_PATH + "talk/" + leftActiveImageFileName).c_str());
	Image* left2Img  = imageFactory->createImage((gameutil::IMAGE_PATH + "talk/" + leftInactiveImageFileName).c_str());
	Image* right1Img = imageFactory->createImage((gameutil::IMAGE_PATH + "talk/" + rightActiveImageFileName).c_str());
	Image* right2Img = imageFactory->createImage((gameutil::IMAGE_PATH + "talk/" + rightInactiveImageFileName).c_str());
	
	TalkEvent* talkEvent = new TalkEvent(left1Img, left2Img, right1Img, right2Img);
	
	string temp = readLine();
	assert(temp == "{");
	
	temp = readLine();
	while (temp != "}") {
		assert(temp.find("l:") == 0 || temp.find("r:") == 0 || temp.find("n:") == 0 || temp.find("a:") == 0);
		
		int position;
		if (temp[0] == 'l') {
			position = talkeventutil::pasitiontype::LEFT;
		} else if (temp[0] == 'r') {
			position = talkeventutil::pasitiontype::RIGHT;
		} else if (temp[0] == 'n') {
			position = talkeventutil::pasitiontype::NONE;
		} else if (temp[0] == 'a') {
			position = talkeventutil::pasitiontype::ALONE;
		} else
			assert(0);
		temp = temp.substr(2);
		talkEvent->addTalkEventElement(TalkEventElement(temp, position));
		
		temp = readLine();
	}
	
	return talkEvent;
}