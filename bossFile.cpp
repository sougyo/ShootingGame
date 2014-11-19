#include "bossFile.h"

using std::string;
using bossIO::BossFile;
using bossIO::BossFileElement;
using enemyIO::EnemyFile;

BossFile::BossFile(string bossNameImageString, string bossSubNameImageString, EnemyFile* enemyFile) {
    assert(enemyFile);
    this->bossNameImageString = bossNameImageString;
    this->bossSubNameImageString = bossSubNameImageString;
    this->enemyFile = enemyFile;
}

BossFile::~BossFile(void) {
    delete enemyFile;
}

void BossFile::addBossFileElement(BossFileElement* bossFileElement) {
    bossFileElements.push_back(bossFileElement);
}

const BossFileElement* BossFile::getBossFileElement(int index) const {
    assert(0 <= index && index < getSize());
    return bossFileElements[index];
}
