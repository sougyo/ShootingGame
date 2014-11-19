#ifndef ___GAME_INFORMATION_H
#define ___GAME_INFORMATION_H

#include <cassert>
#include <string>
#include <sstream>
#include "constantField.h"
#include "image.h"
#include "imageFactory.h"
#include "numberDisplay.h"
#include "DirectSound.h"

namespace gamesystem {
    class GameInformation;
    
    namespace endstate {
        const int GAMEPLAYINGSTATE = 0;
        const int GAMEOVERSTATE = 1;
        const int RESTARTSTATE = 2;
        const int QUITSTATE = 3;
        const int STAGECLEARSTATE = 4;
        const int GAMECLEARSTATE = 5;
    }
}

class gamesystem::GameInformation {
public:
    typedef int PlayerType;
    typedef int StageType;
    static const int PLAYER_TYPE_SIZE;
    static const int STAGE_TYPE_SIZE;

private:
    int stageNo;
    StageType stageType;
    PlayerType playerType;
    bool isStoryMode_;
    gamesoundutil::DirectSound* directSound;
    
private:
    int hiscore;
    int score;
    int player;
    int power;
    int bomb;
    int graze;
    int extend;
    graphics::Image* playerImage;
    graphics::Image* bombImage;
    graphics::Image* titleImage;
    graphics::Image* hiscoreLabel;
    graphics::Image* scoreLabel;
    graphics::Image* bombLabel;
    graphics::Image* powerLabel;
    graphics::Image* playerLabel;
    graphics::Image* grazeLabel;
    graphics::Image* extendLabel;
    graphics::Image* maxLabel;
    graphics::Image* lineImage;
    gamesystem::NumberDisplay hiscoreNumberDisplay;
    gamesystem::NumberDisplay scoreNumberDisplay;
    gamesystem::NumberDisplay powerNumberDisplay;
    gamesystem::NumberDisplay grazeNumberDisplay;
    gamesystem::NumberDisplay extendNumberDisplay;
    gamesystem::NumberDisplay nextGrazeNumberDisplay;
    gamesystem::NumberDisplay nextExtendNumberDisplay;

    int state;
    bool isContinue_;
    int nextGraze;
    int nextExtend;
    
private:
    GameInformation(const gamesystem::GameInformation&);
    const gamesystem::GameInformation& operator=(const gamesystem::GameInformation&);
    
public:
    GameInformation(int, StageType, PlayerType, int, int, int);
    ~GameInformation(void);
    
public:
    void draw(void);
    void addScore(int);
    void addPower(void);
    void addPower(int);
    void addExtend(void);
    void addBomb(void);
    void addPlayer(void);
    void addGraze(void);
    
    void subtractPower(int);
    void subtractBomb(void);
    void subtractPlayer(void);
    
    std::string getStageFileName(void) const;
    std::string getFighterName(void) const;
    
    void nextStage(void);
    void continueInitialize(void);

    inline void setState(int state) { this->state = state; }
    inline int getState(void) const { return state; }
    inline int getScore(void) const { return score; }
    inline int getPower(void) const { return power; }
    inline int getBomb(void) const { return bomb; }
    inline int isGamePlaying(void) const { return state == endstate::GAMEPLAYINGSTATE; }
    inline bool isLastStage(void) const { return stageNo == gameutil::LASTSTAGE; }
    inline bool isFullPower(void) const { return power == gameutil::POWER_MAX; }
    inline bool isStoryMode(void) const { return isStoryMode_; }
    inline bool isContinue(void) const { return isContinue_; }
    
    inline int getStageNo(void) const { return stageNo; }
    inline StageType getStageType(void) const { return stageType; }
    inline PlayerType getPlayerType(void) const { return playerType; }
    
private:
    std::string getStageTypeString(void) const;
    int getInitialPower(int);
};

#endif // ___GAME_INFORMATION_H
