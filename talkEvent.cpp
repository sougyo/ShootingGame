#include "talkEvent.h"

using graphics::Image;
using talkeventutil::TalkEvent;
using talkeventutil::TalkEventElement;

TalkEvent::TalkEvent(Image* left1, Image* left2, Image* right1, Image* right2):
        prevKeyStoreElement(static_cast<unsigned char>(0)),
        currentKeyStoreElement(static_cast<unsigned char>(0)) {
    leftActiveImage = left1;
    leftInactiveImage = left2;
    rightActiveImage = right1;
    rightInactiveImage = right2;
    isActive_ = false;
    index = 0;

    font::FontFactory* fontFactory = font::FontFactory::getInstance();
    fontA = fontFactory->createFont(30,300,370,300,24,8,true);
}

TalkEvent::~TalkEvent(void) {
}

void TalkEvent::addTalkEventElement(TalkEventElement element) {
    talkEventElements.push_back(element);
}

void TalkEvent::fire(int, int) {
    if (!isActive_) {
        isActive_ = true;
        index = 0;
    }
}

void TalkEvent::move(void) {
    if (isActive_) {
        if (isShotPushed() || currentKeyStoreElement.isSkip()) {
            index++;
            if (index >= getSize())
                isActive_ = false;
        }
    }
}

void TalkEvent::draw(void){
    if (isActive_) {
        int position = talkEventElements[index].getPosition();
        if (position == talkeventutil::pasitiontype::LEFT) {
            leftActiveImage->drawImage(0, 100, 300);
            rightInactiveImage->drawImage(0, 300, 300);
        } else if (position == talkeventutil::pasitiontype::RIGHT) {
            leftInactiveImage->drawImage(0, 100, 300);
            rightActiveImage->drawImage(0, 300, 300);
        } else if (position == talkeventutil::pasitiontype::NONE) {
            ;
        } else if (position == talkeventutil::pasitiontype::ALONE) {
            leftActiveImage->drawImage(0, 100, 300);
        } else
            assert(0);
        
        graphics::ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "talkBack(350,100).png").c_str())->drawImage(0,200,350);
        graphics::ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + "talk/" + talkEventElements[index].getMessage()).c_str())->drawImage(0,200,350);
    }
}

void TalkEvent::setKeyData(gamesystem::KeyStoreElement keyStoreElement) {
    prevKeyStoreElement = currentKeyStoreElement;
    currentKeyStoreElement = keyStoreElement;
}
