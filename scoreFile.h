#ifndef ___SCORE_FILE_H
#define ___SCORE_FILE_H

#include <cassert>
#include <map>
#include <string>
#include "scoreStock.h"
#include "gameInformation.h"

namespace gamesystemIO {
    class ScoreFile;
}

class gamesystemIO::ScoreFile {
private:
    std::map<int, gamesystemIO::ScoreStock*> scoreFileElements;
    
private:
    ScoreFile(const gamesystemIO::ScoreFile&);
    const gamesystemIO::ScoreFile& operator=(const gamesystemIO::ScoreFile&);

public:
    ScoreFile(void);
    ~ScoreFile(void);
    
public:
    void addScore(int, gamesystem::GameInformation::StageType, gamesystem::GameInformation::PlayerType, std::string, int);
    gamesystemIO::ScoreStock* getScoreStock(int, gamesystem::GameInformation::StageType, gamesystem::GameInformation::PlayerType);
    
private:
    int makeKey(int, gamesystem::GameInformation::StageType, gamesystem::GameInformation::PlayerType);
};

#endif // ___SCORE_FILE_H
