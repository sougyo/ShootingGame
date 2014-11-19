#include "effect.h"

using effectutil::Effect;
using graphics::Image;

int Effect::count = 0; // デバッグ用

Effect::Effect(int maxSize) : maxSize(maxSize), size(0), x(0), y(0), time(0), isActive_(false) {
	images = new Image*[maxSize];
	
	count++; // デバッグ用
}

Effect::~Effect(void) {
	delete[] images;
	
	count--; // デバッグ用
}

void Effect::addEffectImage(Image* image) {
	assert(0 <= size && size <= maxSize);
	images[size++] = image;
}

void Effect::fire(int x, int y) {
	if (isOutOfDisplay(x, y) || isActive_)
		return;
	
	this->x = x;
	this->y = y;
	isActive_ = true;
	time = 0;
}

void Effect::move(void) {
	if (time >= size) {
		isActive_ = false;
		return;
	}
	time++;
}

void Effect::draw(void) {
	if (isActive() && time < size)
		images[time]->drawImage(0, x, y);
}

bool Effect::isOutOfDisplay(int x, int y) {
	return x < 0 || gameutil::WIDTH < x || y < 0 || gameutil::HEIGHT < y;
}