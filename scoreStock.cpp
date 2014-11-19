#include "scoreStock.h"

using gamesystemIO::Score;
using gamesystemIO::ScoreStock;

ScoreStock::ScoreStock(void) {
}

ScoreStock::~ScoreStock(void) {
}

void ScoreStock::addScore(Score score) {
    scores.push_back(score);
    int lastIndex = getSize() - 1;
    int insertIndex = lastIndex;
    for (int i = 0; i < lastIndex; i++) {
        if (scores[i].getScore() < score.getScore()) {
            insertIndex = i;
            break;
        }
    }
    if (insertIndex == lastIndex)
        return;
    for (int i = lastIndex; i > insertIndex; i--)
        scores[i] = scores[i - 1];
    scores[insertIndex] = score;
}

Score ScoreStock::getScore(int index) {
    if (index < static_cast<int>(scores.size()))
        return scores[index];
    return Score("", 0);
}
