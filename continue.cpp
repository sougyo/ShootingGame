#include "continue.h"

using gamesystem::Continue;
using gamesystem::KeyStoreElement;
using graphics::ImageFactory;

Continue::Continue(void) : 
		prevKeyStoreElement(static_cast<unsigned char>(0)),
		currentKeyStoreElement(static_cast<unsigned char>(0x08)) {
	isActive_ = false;
	isYesState = true;
	isContinue_ = false;
	isNotContinue_ = false;

	ImageFactory* imageFactory = ImageFactory::getInstance();
	yesImage1 = imageFactory->createImage((gameutil::STATE_IMAGE_PATH + "yes1(67,43).png").c_str());
	yesImage2 = imageFactory->createImage((gameutil::STATE_IMAGE_PATH + "yes2(67,43).png").c_str());
	noImage1 = imageFactory->createImage((gameutil::STATE_IMAGE_PATH + "no1(67,43).png").c_str());
	noImage2 = imageFactory->createImage((gameutil::STATE_IMAGE_PATH + "no2(67,43).png").c_str());
	titleImage = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "continue(190,50).png").c_str());
}

Continue::~Continue(void) {
}

void Continue::setKeyData(KeyStoreElement keyStoreElement) {
	prevKeyStoreElement = currentKeyStoreElement;
	currentKeyStoreElement = keyStoreElement;
}

void Continue::move(void) {
	if (isActive_) {
		if (isShotPushed()) {
			if (isYesState)
				isContinue_ = true;
			else
				isNotContinue_ = true;
		}
		if (isLeftPushed() || isRightPushed() || isUpPushed() || isDownPushed())
			isYesState = !isYesState;
	}
}

void Continue::draw(void) {
	if (isActive_) {
		if (isYesState) {
			yesImage1->drawImage(0, 250, 250);
			noImage2->drawImage(0, 350, 250);
		} else {
			yesImage2->drawImage(0, 250, 250);
			noImage1->drawImage(0, 350, 250);
		}
		titleImage->drawImage(0, 300, 150);
	}
}

void Continue::show(void) {
	isActive_ = true;
}