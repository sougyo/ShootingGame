#include "bulletFile.h"

using std::vector;
using bulletIO::BulletFile;
using bulletIO::BulletFileElement;

BulletFile::BulletFile(void) {
}

BulletFile::~BulletFile(void) {
}

void BulletFile::addBulletFileElement(BulletFileElement bulletFileElement) {
    bulletFileElements.push_back(bulletFileElement);
}

const BulletFileElement* BulletFile::getBulletFileElement(int index) const {
    assert(index < getSize());
    return &bulletFileElements[index];
}

const BulletFileElement* BulletFile::searchBulletFileElement(std::string str) const {
    for (int i = 0; i < getSize(); i++) {
        if (bulletFileElements[i].getBulletName() == str)
            return &bulletFileElements[i];
    }
    return 0;
}

#include <iostream>
using std::cout;
using std::endl;
void BulletFile::dump(void) {
    for (int i = 0; i < static_cast<int>(bulletFileElements.size()); i++) {
        bulletFileElements[i].dump();
    }
}
