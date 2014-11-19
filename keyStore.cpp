#include "keyStore.h"

using gamesystem::KeyStore;
using gamesystem::KeyStoreElement;

KeyStore::KeyStore(void) {	
}

KeyStore::~KeyStore(void) {
}

KeyStore::KeyStore(const gamesystem::KeyStore& x) {
	keyStoreElements = x.keyStoreElements;
}

KeyStore& KeyStore::operator=(const KeyStore& x) {
	if (this != &x) {
		keyStoreElements = x.keyStoreElements;
	}
	return *this;
}

void KeyStore::addKeyStoreElement(bool up, bool down, bool left, bool right, bool shot, bool bomb, bool slow, bool skip, bool pause) {
	keyStoreElements.push_back(KeyStoreElement(up, down, left, right, shot, bomb, slow, skip, pause));
}

void KeyStore::addKeyStoreElement(gamesystem::KeyStoreElement& keyStoreElement) {
	keyStoreElements.push_back(keyStoreElement);
}

KeyStoreElement& KeyStore::getKeyStoreElement(int index) {
	assert(0 <= index && index < getSize());
	return keyStoreElements[index];
}
