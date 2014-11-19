#ifndef ___BOSS_FILE_READER_H
#define ___BOSS_FILE_READER_H

#include <cassert>
#include <string>
#include <sstream>
#include "bossFile.h"
#include "constantField.h"
#include "enemyFileReader.h"
#include "fileReader.h"

namespace bossIO {
    class BossFileReader;
}

class bossIO::BossFileReader : public gameutil::FileReader {
private:
    BossFileReader(const bossIO::BossFileReader&);
    const bossIO::BossFileReader& operator=(const bossIO::BossFileReader&);
    
public:
    BossFileReader(const char*, const char*);
    ~BossFileReader(void);
    
public:
    bossIO::BossFile* createBossFile(void);
    
private:
    bossIO::BossFile* analyzeHeader(void);
    std::string analyzeEnemyName(void);
    std::string analyzeImageFileName(void);
    int analyzeLimit(void);
};

#endif // ___BOSS_FILE_READER_H
