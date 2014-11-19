#include "keyStoreElement.h"

using gamesystem::KeyStoreElement;

KeyStoreElement::KeyStoreElement(bool up, bool down, bool left, bool right, bool shot, bool bomb, bool slow, bool skip, bool pause) {
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
    this->shot = shot;
    this->bomb = bomb;
    this->slow = slow;
    this->skip = skip;
    this->pause = pause;
}

KeyStoreElement::KeyStoreElement(unsigned char keyData) {
	up		= (keyData >> 7) & 1;
	down	= (keyData >> 6) & 1;
	left	= (keyData >> 5) & 1;
	right	= (keyData >> 4) & 1;
	shot	= (keyData >> 3) & 1;
	bomb	= (keyData >> 2) & 1;
	slow	= (keyData >> 1) & 1;
	skip	= (keyData >> 0) & 1;
	pause = false;
}

KeyStoreElement::~KeyStoreElement(void) {
}

unsigned char KeyStoreElement::getUChar(void) const {
	unsigned char result = (up << 7) + (down << 6) + (left << 5) + (right << 4) + (shot << 3) + (bomb << 2) + (slow << 1) + (skip);
	return result;
}