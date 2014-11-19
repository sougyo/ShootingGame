#include "score.h"

using std::string;
using gamesystemIO::Score;

Score::Score(string name, int score) {
	this->name = name;
	this->score = score;
}

Score::~Score(void) {
}
