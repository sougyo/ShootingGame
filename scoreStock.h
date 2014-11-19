#ifndef ___SCORE_STOCK_H
#define ___SCORE_STOCK_H

#include <vector>
#include "score.h"

namespace gamesystemIO {
	class ScoreStock;
}

class gamesystemIO::ScoreStock {
private:
	std::vector<gamesystemIO::Score> scores;
private:
	ScoreStock(const gamesystemIO::ScoreStock&);
	const gamesystemIO::ScoreStock& operator=(const gamesystemIO::ScoreStock&);

public:
	ScoreStock(void);
	~ScoreStock(void);
	
public:
	void addScore(gamesystemIO::Score);
	gamesystemIO::Score getScore(int);
	
	inline int getSize(void) const { return static_cast<int>(scores.size()); }
};

#endif // ___SCORE_STOCK_H
