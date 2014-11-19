#include "bossFileReader.h"

using std::istringstream;
using std::string;
using bossIO::BossFile;
using bossIO::BossFileReader;
using enemyIO::EnemyFileReader;
using gameutil::FileReader;

BossFileReader::BossFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

BossFileReader::~BossFileReader(void) {
}

BossFile* BossFileReader::createBossFile(void) {
    BossFile* bossFile = analyzeHeader();
    while (!in->eof()) {
        string enemy = analyzeEnemyName();
        if (enemy == "")
            break;
        int limit = analyzeLimit();
        string techImg = analyzeImageFileName();
                
        bossFile->addBossFileElement(new BossFileElement(limit, techImg, enemy));
    }
    
    return bossFile;
}

BossFile* BossFileReader::analyzeHeader(void) {
    string enemyFileName = readLine();
    assert(!enemyFileName.find("EnemyFile:"));
    EnemyFileReader enemyFileReader(gameutil::DATA_PATH.c_str(),enemyFileName.substr(10).c_str());

    string bossNameImageString = readLine();
    assert(!bossNameImageString.find("BossNameImage:"));
    
    string bossSubNameImageString = readLine();
    assert(!bossSubNameImageString.find("BossSubNameImage:"));
    
    return new BossFile(bossNameImageString.substr(14), bossSubNameImageString.substr(17), enemyFileReader.createEnemyFile());
}

string BossFileReader::analyzeEnemyName(void) {
    string temp = readLine();
    if (temp == "")
        return temp;
    assert(!temp.find("EnemyName:"));
    return temp.substr(10);
}

string BossFileReader::analyzeImageFileName(void) {
    string temp = readLine();
    assert(!temp.find("TechImage:"));
    return temp.substr(10);
}
int BossFileReader::analyzeLimit(void) {
    string temp = readLine();
    assert(!temp.find("Limit:"));
    istringstream in(temp.substr(6));
    int result;
    in >> result;
    return result;
}
