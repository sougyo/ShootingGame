#include "scoreFile.h"

using std::string;
using gamesystemIO::Score;
using gamesystemIO::ScoreFile;
using gamesystemIO::ScoreStock;
using gamesystem::GameInformation;

ScoreFile::ScoreFile(void) {
}

ScoreFile::~ScoreFile(void) {
}

void ScoreFile::addScore(int stageNo, GameInformation::StageType stageType, GameInformation::PlayerType playerType, string name, int score) {
	int key = makeKey(stageNo, stageType, playerType);
	if (scoreFileElements.find(key) == scoreFileElements.end()) {
		scoreFileElements[key] = new ScoreStock;
	}
	scoreFileElements[key]->addScore(Score(name, score));
}

ScoreStock* ScoreFile::getScoreStock(int stageNo, GameInformation::StageType stageType, GameInformation::PlayerType playerType) {
	ScoreStock* result;
	int key = makeKey(stageNo, stageType, playerType);
	if (scoreFileElements.find(key) == scoreFileElements.end())
		result = 0;
	else
		result = scoreFileElements[key];
	return result;
}


int ScoreFile::makeKey(int stageNo, GameInformation::StageType stageType, GameInformation::PlayerType playerType) {
	assert(0 <= stageNo && stageNo <= gameutil::LASTSTAGE);
	assert(0 <= stageType && stageType < GameInformation::STAGE_TYPE_SIZE);
	assert(0 <= playerType && playerType < GameInformation::PLAYER_TYPE_SIZE);
	
	int result = stageNo * 100 + stageType * 10 + playerType;
	return result;
}
