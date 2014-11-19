#ifndef ___MOVE_PATTERN_H
#define ___MOVE_PATTERN_H

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <string>
#include "enemyDeclaration.h"
#include "gamefwd.h"
#include "gameMath.h"
#include "fighter.h"
#include "table.h"

namespace gameutil {
	struct MovePatternElement;
}

#include "moveable.h"

struct gameutil::MovePatternElement {
	double ar;
	double atheta;
	unsigned time;
};

class gameutil::MovePattern {
public:
	static gameutil::Table<enemyutil::Enemy>* enemyTable;
	static gameutil::Table<enemyutil::Enemy>* bossEnemyTable;
	
public:
	enum Kind { Normal = 900000, Aim, Break, Homing };

public:
	static gamesystem::Fighter* fighter;
	
private:
	int maxSize;
	int size;
	int currentTime;
	gameutil::MovePatternElement* movePatternElements;

private:
	MovePattern(const MovePattern&);
	MovePattern& operator=(const MovePattern&);

public:
	explicit MovePattern(int);
	MovePattern(double, double, unsigned);
	~MovePattern(void);
	
public:
	void add(double, double, unsigned);
	void move(gameutil::Moveable*);
	void checkIndex(int*, int);
	inline int getSize(void) const { return size; }
	inline int isAim(int index) const { return movePatternElements[index].atheta == Aim; }
	inline int isHoming(int index) const { return movePatternElements[index].atheta == Homing; }

	static int count;
	void dump(void);
	
private:
	inline double getAimTheta(gameutil::Moveable*);
	inline double getHomingTheta(gameutil::Moveable*);
};

#endif // ___MOVE_PATTERN_H
