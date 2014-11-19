#ifndef ___BULLET_PATTERN_FACTORY_H
#define ___BULLET_PATTERN_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "bulletFile.h"
#include "bulletPattern.h"

namespace factory {
    class BulletPatternFactory;
}

class factory::BulletPatternFactory {
private:
    const bulletIO::BulletFile* bulletFile;
    
private:
    BulletPatternFactory(const factory::BulletPatternFactory&);
    factory::BulletPatternFactory& operator=(const factory::BulletPatternFactory&);

public:
    explicit BulletPatternFactory(const bulletIO::BulletFile*);
    ~BulletPatternFactory(void);

public:
    bulletutil::BulletPattern* createBulletPattern(std::string);

private:
    void changeKeyStringToValueString(std::string*);
    void replaceAll(std::string*, std::string, int);
};

#endif // ___BULLET_PATTERN_FACTORY_H
