#ifndef ___ENEMY_FILE_H
#define ___ENEMY_FILE_H

#include <cassert>
#include <string>
#include <vector>
#include "enemyDeclaration.h"
#include "bulletFile.h"
#include "enemy.h"
#include "enemyFileElement.h"
#include "enemyFactory.h"

class enemyIO::EnemyFile {
private:
    std::vector<enemyIO::EnemyFileElement> enemyFileElements;
    bulletIO::BulletFile* bulletFile;

private:
    EnemyFile(const enemyIO::EnemyFile&);
    enemyIO::EnemyFile& operator=(const enemyIO::EnemyFile&);
    
public:
    explicit EnemyFile(bulletIO::BulletFile*);
    ~EnemyFile(void);
    
public:
    void addEnemyFileElement(enemyIO::EnemyFileElement);
    const enemyIO::EnemyFileElement* getEnemyFileElement(int) const;
    const enemyIO::EnemyFileElement* searchEnemyFileElement(std::string) const;
    enemyutil::Enemy* createEnemy(std::string);

    inline int getSize(void) const { return static_cast<int>(enemyFileElements.size()); }
    inline const bulletIO::BulletFile * getBulletFile(void) const { return bulletFile; }
    
    void dump(void);
};

#endif // ___ENEMY_FILE_H
