#include "gameInformation.h"
#include "gameMath.h"

using std::string;
using std::ostringstream;
using gamesystem::GameInformation;
using graphics::Image;
using graphics::ImageFactory;

const int GameInformation::PLAYER_TYPE_SIZE = 3;
const int GameInformation::STAGE_TYPE_SIZE = 4;

GameInformation::GameInformation(int stageNo, StageType stageType, PlayerType playerType, int hiscore, int score, int player) : hiscoreNumberDisplay(9, 480, 30), scoreNumberDisplay(9, 480, 60), powerNumberDisplay(3, 480, 150), grazeNumberDisplay(4, 480, 180), extendNumberDisplay(2, 480, 210), nextGrazeNumberDisplay(4, 535, 180), nextExtendNumberDisplay(2, 510, 210) {
    if (stageNo == 0) {
        isStoryMode_ = true;
        stageNo++;
    } else
        isStoryMode_ = false;
    this->stageNo = stageNo;
    this->stageType = stageType;
    this->playerType = playerType;
    this->hiscore = hiscore;
    this->score = score;
    this->player = player;
    this->power = getInitialPower(stageNo);
    this->bomb = gameutil::BOMB_INITIALVALUE;
    this->graze = 0;
    this->extend = 0;
    this->state = endstate::GAMEPLAYINGSTATE;
    this->isContinue_ = false;
    this->playerImage = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + "fighterCounter(15,15).png").c_str());
    this->bombImage = ImageFactory::getInstance()->createImage((gameutil::IMAGE_PATH + "bombCounter(15,15).png").c_str());
    this->titleImage = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH+ "logo(200,240).png").c_str());

    this->hiscoreLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "hiscore(50,20).png").c_str());
    this->scoreLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "score(50,20).png").c_str());
    this->bombLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "bomb(50,20).png").c_str());
    this->powerLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "power(50,20).png").c_str());
    this->playerLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "player(50,20).png").c_str());
    this->grazeLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "graze(50,20).png").c_str());
    this->extendLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "extend(50,20).png").c_str());
    this->maxLabel = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "max(80,16).png").c_str());
    this->lineImage = ImageFactory::getInstance()->createImage((gameutil::LABEL_IMAGE_PATH + "line(2,14).png").c_str());

    nextGraze = stageType == 0 ? 100 : 300;
    nextExtend = 50;

    directSound = gamesoundutil::DirectSound::getInstance();
}

GameInformation::~GameInformation(void) {
}

void GameInformation::draw(void) {
    hiscoreLabel->drawImage(0, 440, 30);
    hiscoreNumberDisplay.draw(hiscore);
    scoreLabel->drawImage(0, 440, 60);
    scoreNumberDisplay.draw(score);

    playerLabel->drawImage(0, 440, 90);
    for (int i = 0; i < player-1; i++)
        playerImage->drawImage(0, 480 + i*17, 90);
    bombLabel->drawImage(0, 440, 120);
    for (int i = 0; i < bomb; i++)
        bombImage->drawImage(0, 480 + i*17, 120);
    titleImage->drawImage(0, 520, 330);
    
    powerLabel->drawImage(0, 440, 150);
    if (power == gameutil::POWER_MAX)
        maxLabel->drawImage(0,510,150);
    else
        powerNumberDisplay.draw(power);
        
    grazeLabel->drawImage(0, 440, 180);
    grazeNumberDisplay.draw(graze);
    nextGrazeNumberDisplay.draw((static_cast<int>((graze / nextGraze)) + 1) * nextGraze);
    lineImage->drawImage(gamemath::toRadian(20), 525, 180);
    
    extendLabel->drawImage(0, 440, 210);
    extendNumberDisplay.draw(extend);
    nextExtendNumberDisplay.draw(nextExtend);
    lineImage->drawImage(gamemath::toRadian(20), 500, 210);
}

void GameInformation::addScore(int score) {
    this->score += score;
    if (this->score > hiscore)
        hiscore = this->score;
}

void GameInformation::addPower(void) {
    if (power == gameutil::POWER_MAX) {
        addExtend();
        return;
    }
    this->power++;
    assert(0 <= this->power && this->power <= gameutil::POWER_MAX);
}

void GameInformation::addPower(int power) {
    if (this->power == gameutil::POWER_MAX) {
        addExtend();
        return;
    }
    this->power += power;
    if (this->power > gameutil::POWER_MAX)
        this->power = gameutil::POWER_MAX;
    assert(0 <= this->power && this->power <= gameutil::POWER_MAX);
}

void GameInformation::addExtend(void) {
    extend++;
    if (extend >= nextExtend) {
        addPlayer();
        extend = 0;
    }
}

void GameInformation::addBomb(void) {
    assert(0 <= bomb && bomb <= gameutil::BOMB_MAX);
    if (bomb == gameutil::BOMB_MAX)
        return;
    this->bomb++;
    directSound->playGameSE(4);
}

void GameInformation::addPlayer(void) {
    assert(0 <= player && player <= gameutil::PLAYER_MAX);
    if (player == gameutil::PLAYER_MAX) {
        addBomb();
        return;
    }
    this->player++;
    directSound->playGameSE(3);
}

void GameInformation::addGraze(void) {
    this->graze++;
    directSound->playGameSE(5);
    if (graze % nextGraze == 0)
        addBomb();
}

void GameInformation::subtractPower(int power) {
    this->power -= power;
    if (this->power < 0)
        this->power = 0;
    assert(0 <= this->power && this->power <= gameutil::POWER_MAX);
}

void GameInformation::subtractBomb(void) {
    if (bomb > 0) {
        bomb--;
        directSound->playGameSE(0);
    }
}

void GameInformation::subtractPlayer(void) {
    player--;
    directSound->playGameSE(1);
    if (player == 0)
        state = endstate::GAMEOVERSTATE;
    bomb = gameutil::BOMB_INITIALVALUE;
    subtractPower(5);
}

string GameInformation::getStageTypeString(void) const {
    string result;
    
    switch (stageType) {
        case 0:
            result = "easy";
            break;
        case 1:
            result = "normal";
            break;
        case 2:
            result = "hard";
            break;
        case 3:
            result = "ultimate";
            break;
        default:
            assert(0);
    }
    return result;
}

string GameInformation::getFighterName(void) const {
    string result;
    switch (playerType) {
        case 0:
            result = "fighter1";
            break;
        case 1:
            result = "fighter2";
            break;
        case 2:
            result = "fighter3";
            break;
        default:
            assert(0);
    }
    return result;
}

string GameInformation::getStageFileName(void) const {
    ostringstream out;

    out << "stage" << stageNo << "_" << getStageTypeString() << ".itp";
    return out.str();
}

void GameInformation::nextStage(void) {
    assert(0 <= stageNo && stageNo < gameutil::LASTSTAGE);
    stageNo++;
    score += graze * 500;
    state = endstate::GAMEPLAYINGSTATE;
}

void GameInformation::continueInitialize(void) {
    score = 0;
    player = gameutil::PLAYER_MAX;
    power = gameutil::POWER_MAX;
    bomb = gameutil::BOMB_INITIALVALUE;
    graze = 0;
    extend = 0;
    state = endstate::GAMEPLAYINGSTATE;
    isContinue_ = true;
}

int GameInformation::getInitialPower(int stageNo) {
    int result;
    switch (stageNo) {
        case 0:
        case 1:
            result = 0;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            result = gameutil::POWER_MAX;
            break;
        default:
            assert(0);
    }
    return result;
}
