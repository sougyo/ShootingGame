#include "enemy.h"

using bulletutil::Bullet;
using bulletutil::BulletPattern;
using enemyutil::Enemy;
using enemyutil::EnemyElement;
using enemyutil::EnemyPattern;
using gameutil::ImagePattern;
using gameutil::MovePattern;
using graphics::Image;
using itemutil::Item;
using missileutil::Missile;

gameutil::Table<Bullet>* Enemy::bulletTable = 0;
gameutil::Table<Enemy>* Enemy::enemyTable = 0;
gameutil::Table<Item>* Enemy::itemTable = 0;

Enemy::Enemy(int maxSize, int hp, bool canCollide, MovePattern* movePattern, BulletPattern* bulletPattern, EnemyPattern* enemyPattern, ImagePattern* imagePattern, Image* image)
		: maxSize(maxSize), size(0), hp(hp), canCollide(canCollide), isActive_(false), activeCount(0) {
	this->movePattern = movePattern;
	this->bulletPattern = bulletPattern;
	this->enemyPattern = enemyPattern;
	this->imagePattern = imagePattern;
	this->image = image;
	radius = static_cast<int>(image->getRadius() * 0.8);
	enemyElements = new EnemyElement*[maxSize];
}

Enemy::~Enemy(void) {
	for (int i = 0; i < size; i++)
		delete enemyElements[i];
	delete[] enemyElements;
	delete movePattern;
	delete bulletPattern;
	delete enemyPattern;
	if (imagePattern != 0)
		delete imagePattern;
}

void Enemy::addEnemyElement(double x, double y, double vr, double vtheta, int time, int delay, double angle, Item* item) {
	assert(size < maxSize);
	assert(time >= 0);
	Bullet** bullets = bulletPattern->createBulletArray();
	Bullet** killedBullets = bulletPattern->createKilledBulletArray();
	Enemy** enemys = enemyPattern->createEnemyArray();
	rotateBullets(bullets, bulletPattern->getBulletSize(), gamemath::toRadian(angle));
	rotateBullets(killedBullets, bulletPattern->getKilledBulletSize(), gamemath::toRadian(angle));
	enemyElements[size++] = new EnemyElement(this, x, y, vr, gamemath::toRadian(vtheta), -time, delay, hp, bullets, killedBullets, enemys, item);
}

void Enemy::fire(int x, int y) {
	if (!isActive_) {
		isActive_ = true;
		activeCount = size;
		for (int i = 0; i < size; i++)
			enemyElements[i]->fire(x, y);
	}
}

void Enemy::move(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++) {
			enemyElements[i]->move();
		}
		if (activeCount == 0)
			isActive_ = false;
	}
}

void Enemy::draw(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++)
			enemyElements[i]->draw();
	}
}

EnemyElement* Enemy::getEnemyElement(int index) {
	assert(index >= 0 && index < size);
	return enemyElements[index];
}

void Enemy::rotateBullets(Bullet** bullets, int bulletSize, double angle) {
	for (int i = 0; i < bulletSize; i++)
		bullets[i]->rotate(angle);
}

void Enemy::checkCollision(bombutil::Bomb* bomb) {
	int distance = getRadius() + bomb->getRadius();
	for (int i = 0; i < size; i++)
		enemyElements[i]->checkCollision(bomb, distance);
}

void Enemy::checkCollision(gamesystem::Fighter* fighter) {
	if (fighter->isInvincibility())
		return;
	if (!canCollide)
		return;
	int distance = getRadius() + fighter->getRadius();
	for (int i = 0; i < size; i++)
		enemyElements[i]->checkCollision(fighter, distance);
}

void Enemy::checkCollision(Missile* missile) {
	int distance = getRadius() + missile->getRadius();
	for (int i = 0; i < missile->getSize(); i++)
		for (int j = 0; j < size; j++)
			enemyElements[j]->checkCollision(missile->getMissileElement(i), distance);
}

int Enemy::getHp(int index) {
	return enemyElements[index]->getHp();
}

int Enemy::getScore(void) {
	int score = 0;
	for (int i = 0; i < getSize(); i++)
		score += enemyElements[i]->getScore();
	return score;
}


#include <iostream>
void Enemy::dump(void) {
	std::cout << "\n--EnemyDumpStart" << std::endl;
	std::cout << "x" << '\t' << "y" << '\t' << "r" << '\t' << "theta" << '\t' << "time" << '\t' << "hp" << '\t' << "delay" << std::endl;
	for (int i = 0; i < size; i++)
		enemyElements[i]->dump();
	std::cout << std::endl;
	enemyElements[0]->dumpBullets();
	movePattern->dump();
	bulletPattern->dump();
	std::cout << "--EnemyDumpEnd\n" << std::endl;
}
