#include "gauge.h"

using gameutil::Gauge;
using graphics::Image;
using graphics::ImageFactory;

Gauge::Gauge(int x, int y) {
	this->x = x;
	this->y = y;
	ImageFactory* imageFactory = ImageFactory::getInstance();
	gaugeImages = new Image*[6];
	gaugeImages[0] = imageFactory->createImage((gameutil::GAUGE_IMAGE_PATH + "level1(6,5).png").c_str());
	gaugeImages[1] = imageFactory->createImage((gameutil::GAUGE_IMAGE_PATH + "level2(6,5).png").c_str());
	gaugeImages[2] = imageFactory->createImage((gameutil::GAUGE_IMAGE_PATH + "level3(6,5).png").c_str());
	gaugeImages[3] = imageFactory->createImage((gameutil::GAUGE_IMAGE_PATH + "level4(6,5).png").c_str());
	gaugeImages[4] = imageFactory->createImage((gameutil::GAUGE_IMAGE_PATH + "level5(6,5).png").c_str());
	gaugeImages[5] = imageFactory->createImage((gameutil::GAUGE_IMAGE_PATH + "level6(6,5).png").c_str());
}

Gauge::~Gauge(void) {
	delete[] gaugeImages;
}

void Gauge::add(int hp) {
	hpArray.push_back(hp);
}

void Gauge::draw(int index, int hp) {
	drawGauge(index, getGaugeNumber(index, hp));
	
	for (int i = index + 1; i < getSize(); i++)
		drawGauge(i, GAUGE_MAXNUMBER / getSize());
}

void Gauge::drawGauge(int index, int number) {
	for (int i = 0; i < number; i++) {
		gaugeImages[index]->drawImage(0, i * GAUGE_WIDTH / GAUGE_MAXNUMBER + getLeftPosition(index), y);
	}
}