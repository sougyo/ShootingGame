#ifndef ___BULLET_FILE_READER_H
#define ___BULLET_FILE_READER_H

#include <cassert>
#include <string>
#include "bulletFile.h"
#include "fileReader.h"

namespace bulletIO {
    class BulletFileReader;
}

class bulletIO::BulletFileReader : public gameutil::FileReader {
private:
    BulletFileReader(const bulletIO::BulletFileReader&);
    bulletIO::BulletFileReader& operator=(const bulletIO::BulletFileReader&);
    
private:
    explicit BulletFileReader(const char*);
    
public:
    BulletFileReader(const char*, const char*);
    ~BulletFileReader(void);

public:
    bulletIO::BulletFile* createBulletFile(void);
    
private:
    std::string analyzeBulletName(std::string);
    std::string analyzeImageFileName(void);
    std::string analyzeInitialStateString(void);
    std::string analyzeMovePatternString(void);
    void ignoreMemoString(void);
};

#endif // ___BULLET_FILE_READER_H
