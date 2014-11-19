#include "numberDisplay.h"

using gamesystem::NumberDisplay;
using gameutil::NUMBER_IMAGE_PATH;
using graphics::Image;
using graphics::ImageFactory;

NumberDisplay::NumberDisplay(int digit, int x, int y) {
	this->digit = digit;
	this->x = x;
	this->y = y;
	ImageFactory* imageFactory = ImageFactory::getInstance();
	zero  = imageFactory->createImage((NUMBER_IMAGE_PATH + "zero(12,16).png").c_str());
	one   = imageFactory->createImage((NUMBER_IMAGE_PATH + "one(12,16).png").c_str());
	two   = imageFactory->createImage((NUMBER_IMAGE_PATH + "two(12,16).png").c_str());
	three = imageFactory->createImage((NUMBER_IMAGE_PATH + "three(12,16).png").c_str());
	four  = imageFactory->createImage((NUMBER_IMAGE_PATH + "four(12,16).png").c_str());
	five  = imageFactory->createImage((NUMBER_IMAGE_PATH + "five(12,16).png").c_str());
	six   = imageFactory->createImage((NUMBER_IMAGE_PATH + "six(12,16).png").c_str());
	seven = imageFactory->createImage((NUMBER_IMAGE_PATH + "seven(12,16).png").c_str());
	eight = imageFactory->createImage((NUMBER_IMAGE_PATH + "eight(12,16).png").c_str());
	nine  = imageFactory->createImage((NUMBER_IMAGE_PATH + "nine(12,16).png").c_str());
}

NumberDisplay::~NumberDisplay(void) {
}

void NumberDisplay::draw(int number) {
	assert(0 < digit && digit < 10);
	assert(number >= 0 && number < pow(10, digit));

	for (int i = 0; i < digit; i++) {
		const int imageWidth = 12;
		int temp = static_cast<int>(pow(10, digit - i - 1));
		switch (number / temp) {
			case 0:
				zero->drawImage(0, x + imageWidth * i, y);
				break;
			case 1:
				one->drawImage(0, x + imageWidth * i, y);
				break;
			case 2:
				two->drawImage(0, x + imageWidth * i, y);
				break;
			case 3:
				three->drawImage(0, x + imageWidth * i, y);
				break;
			case 4:
				four->drawImage(0, x + imageWidth * i, y);
				break;
			case 5:
				five->drawImage(0, x + imageWidth * i, y);
				break;
			case 6:
				six->drawImage(0, x + imageWidth * i, y);
				break;
			case 7:
				seven->drawImage(0, x + imageWidth * i, y);
				break;
			case 8:
				eight->drawImage(0, x + imageWidth * i, y);
				break;
			case 9:
				nine->drawImage(0, x + imageWidth * i, y);
				break;
			default:
				assert(0);
				break;
		}
		number %= temp;
	}
}
