#include "pause.h"

using gamesystem::KeyStoreElement;
using gamesystem::Pause;
using graphics::Image;
using graphics::ImageFactory;
using gamesystem::GameInformation;

const int Pause::INDEXMAX = 2;

Pause::Pause(GameInformation* gameInformation) : prevKeyStoreElement(static_cast<unsigned char>(0)), currentKeyStoreElement(static_cast<unsigned char>(0)) {
    isActive_ = false;
    index = 0;
    releaseCount = -1;
    this->gameInformation = gameInformation;
    
    ImageFactory* imageFactory = ImageFactory::getInstance();
    cancelImage1    = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "pausecancel1(185,25).png").c_str());
    cancelImage2    = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "pausecancel2(185,25).png").c_str());
    restartImage1   = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "pauserestart1(185,25).png").c_str());
    restartImage2   = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "pauserestart2(185,25).png").c_str());
    quitImage1      = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "pauseend1(185,25).png").c_str());
    quitImage2      = imageFactory->createImage((gameutil::LABEL_IMAGE_PATH + "pauseend2(185,25).png").c_str());
}

Pause::~Pause(void) {
}

void Pause::setKeyData(KeyStoreElement keyStoreElement) {
    prevKeyStoreElement = currentKeyStoreElement;
    currentKeyStoreElement = keyStoreElement;
    
    if (!isActive_) {
        if (isPausePushed()) {
            isActive_ = true;
            releaseCount = -1;
            index = 0;
        }
    } else {
        if (isShotPushed()) {
            if (index == 0)
                releasePause();
            else if (index == 1) {
                gameInformation->setState(endstate::RESTARTSTATE);
                releasePause();
            }
            else if (index == 2) {
                gameInformation->setState(endstate::QUITSTATE);
                releasePause();
            }
        }
        if (isBombPushed()) {
            releasePause();
        }
        const int MENUNUMBER = 3;
        if (isUpPushed()) {
            index = (index + MENUNUMBER - 1) % MENUNUMBER;
        }
        if (isDownPushed()) {
            index = (index + 1) % MENUNUMBER;
        }
    }
}

void Pause::draw(void) {
    const int XPOSITION = 200;
    const int YPOSITION = 150;
    const int INTERVAL = 50;
    if (isActive_) {
        if (index == 0)
            cancelImage1->drawImage(0, XPOSITION, YPOSITION + INTERVAL * 0);
        else
            cancelImage2->drawImage(0, XPOSITION, YPOSITION + INTERVAL * 0);

        if (index == 1)
            restartImage1->drawImage(0, XPOSITION, YPOSITION + INTERVAL * 1);
        else
            restartImage2->drawImage(0, XPOSITION, YPOSITION + INTERVAL * 1);

        if (index == 2)
            quitImage1->drawImage(0, XPOSITION, YPOSITION + INTERVAL * 2);
        else
            quitImage2->drawImage(0, XPOSITION, YPOSITION + INTERVAL * 2);
    }
}

void Pause::move(void) {
    if (isActive_) {
        assert(0 <= index && index <= INDEXMAX);
        releaseCount--;
        if (releaseCount == 0)
            isActive_ = false;
    }
}
