#ifndef ___MOVE_PATTERN_FACTORY_H
#define ___MOVE_PATTERN_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "movePattern.h"

namespace factory {
    class MovePatternFactory;
}

class factory::MovePatternFactory {
private:
    MovePatternFactory(factory::MovePatternFactory&);
    factory::MovePatternFactory& operator=(factory::MovePatternFactory);

public:
    MovePatternFactory(void);
    ~MovePatternFactory(void);
    gameutil::MovePattern* createMovePattern(std::string);

private:
    std::string& changeAimToValue(std::string&);
    std::string& changeHomingToValue(std::string&);
};

#endif // ___MOVE_PATTERN_FACTORY_H
