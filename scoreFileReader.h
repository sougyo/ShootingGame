#ifndef ___SCORE_FILE_READER_H
#define ___SCORE_FILE_READER_H

#include <algorithm>
#include <string>
#include <sstream>
#include "fileReader.h"
#include "scoreFile.h"
#include "gameInformation.h"

namespace gamesystemIO {
    class ScoreFileReader;
}

class gamesystemIO::ScoreFileReader : public gameutil::FileReader {
private:
    ScoreFileReader(const gamesystemIO::ScoreFileReader&);
    const gamesystemIO::ScoreFileReader& operator=(const gamesystemIO::ScoreFileReader&);
    
public:
    ScoreFileReader(const char*);
    ~ScoreFileReader(void);
    
public:
    gamesystemIO::ScoreFile* createScoreFile(void);
};

#endif // ___SCORE_FILE_READER_H
