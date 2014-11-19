#ifndef ___LABEL_H
#define ___LABEL_H

#include <cmath>
#include "angle.h"
#include "gameMath.h"
#include "Image.h"
#include "labelMovePattern.h"

namespace labelutil {
	class Label;
}

class labelutil::Label {
private:
	double initX;
	double initY;
	double initZ;
	double initVr;
	double initVtheta;
	double initVphi;
	
	double x;
	double y;
	double z;
	double vr;
	double vtheta;
	double vphi;
	labelutil::Angle angle;
	labelutil::Angle vangle;
	
	bool isActive_;
	
private:
	graphics::Image* image;
	labelutil::LabelMovePattern* labelMovePattern;
	
private:
	Label(const labelutil::Label&);
	const labelutil::Label& operator=(const labelutil::Label&);
	
public:
	Label(int, int, int, double, double, double, graphics::Image*, labelutil::LabelMovePattern*);
	~Label(void);
	
public:
	void fire(int, int);
	void move(void);
	void draw(void);
	
	inline bool isActive(void) const { return isActive_; }
	inline int getX(void) const { return static_cast<int>(x); }
	inline int getY(void) const { return static_cast<int>(y); }
	inline int getZ(void) const { return static_cast<int>(z); }
};

#endif // ___LABEL_H