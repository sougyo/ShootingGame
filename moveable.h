#ifndef ___MOVEABLE_H
#define ___MOVEABLE_H

#include <cmath>
#include "gamefwd.h"
#include "constantField.h"

class gameutil::Moveable {
private:
	friend class gameutil::MovePattern;

protected:
	double x;
	double y;
	double vr;
	double vtheta;
	int time;
	int movePatternIndex;
	bool isActive_;
	
private:
	Moveable(const gameutil::Moveable&);
	const gameutil::Moveable& operator=(const gameutil::Moveable&);

public:
	Moveable(void);
	Moveable(double, double, double, double, int);
	
public:
	inline int getX(void) const { return static_cast<int>(x); }
	inline int getY(void) const { return static_cast<int>(y); }
	inline double getVX(void) const { return vr * std::cos(vtheta); }
	inline double getVY(void) const { return vr * std::sin(vtheta); }
	inline double getVtheta(void) const { return vtheta; }
	inline bool isActive(void) const { return isActive_; }
	inline bool isAppearance(void) const { return isActive_ && time >= 0; }

public:
	void translate(double, double);

protected:
	inline bool isOutOfDisplay(void) const { return gameutil::LEFT >= x || gameutil::RIGHT <= x || gameutil::TOP >= y || gameutil::BOTTOM <= y; }
};

#endif // ___MOVEABLE_H
