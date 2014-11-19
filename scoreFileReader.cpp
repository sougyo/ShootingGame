#include "scoreFileReader.h"

using std::string;
using std::istringstream;
using gameutil::FileReader;
using gamesystem::GameInformation;
using gamesystemIO::ScoreFile;
using gamesystemIO::ScoreFileReader;

ScoreFileReader::ScoreFileReader(const char* fileName) : FileReader(fileName) {
}

ScoreFileReader::~ScoreFileReader(void) {
}

gamesystemIO::ScoreFile* ScoreFileReader::createScoreFile(void) {
    ScoreFile* scoreFile = new ScoreFile;
    
    string temp = readLine();
    while (temp != ":END") {
        if (in->eof() || static_cast<int>(std::count(temp.begin(), temp.end(), ' ')) != 4) {
            return 0;
        }
        
        istringstream in(temp);
        int stageNo;
        GameInformation::StageType stageType;
        GameInformation::PlayerType playerType;
        string name;
        int score;
        
        in >> stageNo >> stageType >> playerType >> name >> score;
        scoreFile->addScore(stageNo, stageType, playerType, name, score);
        
        temp = readLine();
    }
    return scoreFile;
}
