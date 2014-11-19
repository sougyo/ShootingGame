#include "enemyElement.h"

using bulletutil::Bullet;
using bulletutil::BulletElement;
using enemyutil::EnemyElement;
using enemyutil::Enemy;
using effectutil::EffectPool;
using gameutil::Moveable;
using itemutil::Item;

EffectPool* EnemyElement::effectPool = 0;
gamesystem::GameInformation* EnemyElement::gameInformation = 0;
int EnemyElement::count = 0;

EnemyElement::EnemyElement(enemyutil::Enemy* owner, double x, double y, double vr, double vtheta, int time, int delay, int hp, Bullet** bullets, Bullet** killedBullets, Enemy** enemys, Item* item)
        : Moveable(x, y, vr, vtheta, time) {
    this->owner = owner;
    this->delay = delay;
    this->hp = hp;
    this->bulletPatternIndex = 0;
    this->enemyPatternIndex = 0;
    this->imagePatternIndex = 0;
    this->bullets = bullets;
    this->enemys = enemys;
    this->killedBullets = killedBullets;
    this->item = item;
    score = getScore();
    
    count++;
}

EnemyElement::~EnemyElement(void) {
    for (int i = 0; i < getBulletSize(); i++)
        delete bullets[i];
    for (int i = 0; i < getKilledBulletSize(); i++)
        delete killedBullets[i];
    for (int i = 0; i < getEnemySize(); i++)
        delete enemys[i];
    delete[] bullets;
    delete[] killedBullets;
    delete item;
    
    count--;
}

void EnemyElement::fire(int x, int y) {
    this->x += x;
    this->y += y;
    isActive_ = true;
}

void EnemyElement::move(void) {
    if (isActive_) {
        owner->movePattern->move(this);
        followProcess();
        fireBulletProcess();
        fireEnemyProcess();
        if (isOutOfDisplay())
            toInactive();
        if (hp <= 0)
            killedProcess();
    }
}

void EnemyElement::draw(void) {
    if (isAppearance()) {
        if (owner->imagePattern == 0)
            owner->image->drawImage(0, getX(), getY());
        else
            owner->imagePattern->getImage(imagePatternIndex, time)->drawImage(0, getX(), getY());
    }
}

void EnemyElement::checkCollision(bombutil::Bomb* bomb, int distance) {
    if (gameutil::checkCollision(this, bomb, distance)) {
        hp--;
    }
}

void EnemyElement::checkCollision(gamesystem::Fighter* fighter, int distance) {
    if (gameutil::checkCollision(this, fighter, distance)) {
        fighter->collision();
    }
}

void EnemyElement::checkCollision(missileutil::MissileElement* missileElement, int distance) {
    if (gameutil::checkCollision(this, missileElement, distance)) {
        hp--;
        missileElement->toInactive();
    }
}

Bullet* EnemyElement::getBullet(int index) {
    assert(index >= 0 && index < getBulletSize());
    return bullets[index];
}

Bullet* EnemyElement::getKilledBullet(int index) {
    assert(index >= 0 && index < getKilledBulletSize());
    return killedBullets[index];
}

int EnemyElement::getScore(void) {
    int score = 0;
    for (int i = 0; i < getBulletSize(); i++)
        score += bullets[i]->getSize();
    for (int i = 0; i < getKilledBulletSize(); i++)
        score += killedBullets[i]->getSize();
    for (int i = 0; i < getEnemySize(); i++)
        score += enemys[i]->getScore();
    
    return score;
}

int EnemyElement::getBulletSize(void) {
    return owner->bulletPattern->getBulletSize();
}

int EnemyElement::getKilledBulletSize(void) {
    return owner->bulletPattern->getKilledBulletSize();
}

int EnemyElement::getEnemySize(void) {
    return owner->enemyPattern->getSize();
}

void EnemyElement::toInactive(void) {
    isActive_ = false;
    owner->activeCount--;
}

void EnemyElement::followProcess(void) {
    for (int i = 0; i < static_cast<int>(owner->bulletPattern->getBulletSize()); i++)
        if (owner->bulletPattern->isFollow(i) && bullets[i]->isActive())
            bullets[i]->translate(getVX(), getVY());
}

void EnemyElement::fireBulletProcess(void) {
    if (owner->bulletPattern->checkIndex(bulletPatternIndex, time - delay)) {
        if(owner->bulletPattern->isDynamic(bulletPatternIndex))
            bullets[bulletPatternIndex]->rotate(vtheta);

        owner->bulletTable->add(bullets[bulletPatternIndex], static_cast<int>(x), static_cast<int>(y));
        bulletPatternIndex++;
    }
}

void EnemyElement::fireEnemyProcess(void) {
    if (owner->enemyPattern->checkIndex(enemyPatternIndex, time)) {
        owner->enemyTable->add(enemys[enemyPatternIndex], static_cast<int>(x), static_cast<int>(y));
        enemyPatternIndex++;
    }
}

void EnemyElement::killedProcess(void) {
    toInactive();
    for (int i = 0; i < getKilledBulletSize(); i++)
        owner->bulletTable->add(killedBullets[i], getX(), getY());
    for (int i = 0; i < getBulletSize(); i++) {
        if (owner->bulletPattern->isFollow(i))
            bullets[i]->kill();
        bullets[i]->deleteExtraBulletElement();
    }
    owner->itemTable->add(item, getX(), getY());
    effectPool->fire(getX(), getY());
    gameInformation->addScore(score);
    gamesoundutil::DirectSound::getInstance()->playGameSE(6);
}

void EnemyElement::deleteFollowBullets(void) {
    
}

#include <iostream>
void EnemyElement::dump(void) {
    std::cout << x << '\t' << y << '\t' << vr << '\t' << vtheta << '\t' << time << '\t' << hp << '\t' << delay << std::endl;
}

void EnemyElement::dumpBullets(void) {
    std::cout << "\n-Enemy's BulletDumpStart" << std::endl;
    for (int i = 0; i < getBulletSize(); i++)
        bullets[i]->dump();
    std::cout << "\n-Enemy's BulletDumpEnd" << std::endl;
    std::cout << "\n-Enemy's KilledBulletDumpStart" << std::endl;
    for (int i = 0; i < getKilledBulletSize(); i++)
        killedBullets[i]->dump();
    std::cout << "\n-Enemy's KilledBulletDumpEnd" << std::endl;
}
