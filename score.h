#ifndef ___SCORE_H
#define ___SCORE_H

#include <string>

namespace gamesystemIO {
    class Score;
}

class gamesystemIO::Score {
private:
    std::string name;
    int score;
    
public:
    Score(std::string, int);
    ~Score(void);
    
public:
    inline std::string getName(void) const { return name; }
    inline int getScore(void) const { return score; }
};

#endif //___SCORE_H
