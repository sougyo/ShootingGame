#include "enemyPattern.h"

using enemyutil::Enemy;
using enemyutil::EnemyPattern;
using enemyutil::EnemyPatternElement;
using enemyIO::EnemyFile;
using enemyIO::EnemyFileElement;
using factory::EnemyFactory;

int EnemyPattern::count = 0;

EnemyPattern::EnemyPattern(const EnemyFile* enemyFile) : currentTime(0) {
    this->enemyFile = enemyFile;
    
    count++;
}

EnemyPattern::~EnemyPattern(void) {
    count--;
}

void EnemyPattern::addEnemyPatternElement(const EnemyFileElement* enemyFileElement, int time) {
    currentTime += time;
    EnemyPatternElement enemyPatternElement;
    enemyPatternElement.enemyFileElement = enemyFileElement;
    enemyPatternElement.time = currentTime;
    enemyPatternElements.push_back(enemyPatternElement);
}

Enemy** EnemyPattern::createEnemyArray(void) {
    EnemyFactory enemyFactory;
    if (enemyPatternElements.size() == 0)
        return 0;

    Enemy** enemys = new Enemy*[enemyPatternElements.size()];
    for (int i = 0; i < static_cast<int>(enemyPatternElements.size()); i++)
        enemys[i] = enemyFactory.createEnemy(enemyFile, *enemyPatternElements[i].enemyFileElement);
    return enemys;
}

bool EnemyPattern::checkIndex(int enemyPatternIndex, int time) {
    assert(enemyPatternIndex >= 0 && enemyPatternIndex <= static_cast<int>(getSize()));
    if (enemyPatternIndex == static_cast<int>(getSize()))
        return false;
    
    if (time == enemyPatternElements[enemyPatternIndex].time)
        return true;
    
    return false;
}
