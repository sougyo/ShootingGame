#include "fighter.h"

using bombutil::Bomb;
using factory::LabelFactory;
using gameutil::Moveable;
using gamesystem::Fighter;
using gamesystem::GameInformation;
using graphics::Image;
using labelutil::Label;
using labelIO::LabelFile;
using labelIO::LabelFileReader;
using missileutil::MissileSetController;

gameutil::Table<bombutil::Bomb>* Fighter::bombTable = 0;
gameutil::Table<labelutil::Label>* Fighter::labelTable = 0;

Fighter::Fighter(int radius, double speed, double slowSpeed, Image* image, MissileSetController* missileSetController) : slowFlag(false), keyFlag(false), attacked_(false) {
    this->missileSetController = missileSetController;
    this->radius = radius;
    this->speed = speed;
    this->slowSpeed = slowSpeed;
    this->bomb_ = new Bomb;
    this->image = image;
    collisionCount = -1;
    invincibilityCount = -1;
    circleImage = graphics::ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + "ccircle(6,6).png").c_str());
    cancelLabel = createCancelLabel();
    x = 200.0;
    y = 400.0;
    vx = vy = 0.0;
}

Fighter::~Fighter(void) {
    delete bomb_;
    delete missileSetController;
    delete cancelLabel;
}

void Fighter::move(void) {
    missileSetController->move();
    if (slowFlag) {
        vx *= 0.5;
        vy *= 0.5;
    }
    if (x + vx > image->getRadius() && x + vx < gameutil::WIDTH - image->getRadius())
        x += vx;
    if (y + vy > image->getRadius() && y + vy < gameutil::HEIGHT - image->getRadius())
        y += vy;
    resetFlags();
    vx = vy = 0.0;
    collisionCount--;
    invincibilityCount--;
    
    if (collisionCount == 0)
        attacked_ = true;
}

void Fighter::draw(void) {
    if (invincibilityCount > 0) {
        if ((invincibilityCount / 10) % 2 == 0)
            image->drawImage(0, static_cast<int>(x), static_cast<int>(y));
    }else {
        image->drawImage(0, static_cast<int>(x), static_cast<int>(y));
    }
    if (!isCollision())
        circleImage->drawImage(0, static_cast<int>(x), static_cast<int>(y));
}

void Fighter::collision(void) { 
    if (!isCollision()) {
        collisionCount = bomb_->isEmpty() ? 1 : COLLISIONCOUNTMAX;
    }
}

void Fighter::initAttacked(void) {
    attacked_ = false;
    toInvincibility();
}

void Fighter::resetFlags(void) {
    slowFlag = false;
    keyFlag = false;
}

void Fighter::up(void) {
    if (keyFlag) {
        vx /= SQRT2;
        vy = -speed / SQRT2;
    } else {
        vy = -speed;
    }
    keyFlag = true;
}

void Fighter::down(void) {
    if (keyFlag) {
        vx /= SQRT2;
        vy = speed / SQRT2;
    } else {
        vy = speed;
    }
    keyFlag = true;
}

void Fighter::left(void) {
    if (keyFlag) {
        vy /= SQRT2;
        vx = -speed / SQRT2;
    } else {
        vx = -speed;
    }
    keyFlag = true;
}

void Fighter::right(void) {
    if (keyFlag) {
        vy /= SQRT2;
        vx = speed / SQRT2;
    } else {
        vx = speed;
    }
    keyFlag = true;
}

void Fighter::slow(void) {
    slowFlag = true;
}

void Fighter::shot(int power) {
    missileSetController->fire(power);
}

void Fighter::bomb(void) {
    if (!bomb_->isActive() && bombTable->getSize() == 0 && !isInvincibility() && !bomb_->isEmpty()) {
        if (isCollision()) {
            collisionCount = -1;
            labelTable->add(cancelLabel, getX(), getY());
        }
        bombTable->add(bomb_, getX(), getY());
    }
}

Label* Fighter::createCancelLabel(void) {
    LabelFileReader labelFileReader(gameutil::DATA_PATH.c_str(), "cancel.lbl");
    LabelFile* labelFile = labelFileReader.createLabelFile();
    LabelFactory labelFactory;
    Label* result = labelFactory.createLabel(*labelFile);
    delete labelFile;
    return result;
}
