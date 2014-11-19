#ifndef ___GAUGE_H
#define ___GAUGE_H

#include <vector>
#include "constantField.h"
#include "Image.h"
#include "ImageFactory.h"

namespace gameutil {
	class Gauge;
	const int GAUGE_WIDTH = 300;
	const int GAUGE_MAXNUMBER = 60;
}

class gameutil::Gauge {
private:
	int x;
	int y;
	std::vector<int> hpArray;
	graphics::Image** gaugeImages;
	
private:
	Gauge(const gameutil::Gauge&);
	const gameutil::Gauge& operator=(const gameutil::Gauge&);
	
public:
	Gauge(int, int);
	~Gauge(void);
	
public:
	void add(int);
	void draw(int, int);
	inline int getSize(void) const { return static_cast<int>(hpArray.size()); }
	
private:
	void drawGauge(int, int);
	inline int getLeftPosition(int index) const { return (getSize() - index - 1) * gameutil::GAUGE_WIDTH / getSize() + x; }
	inline int getGaugeNumber(int index, int hp) const { return (hp-1) * gameutil::GAUGE_MAXNUMBER / (hpArray[index] * getSize()) + 1; }
};

#endif // ___GAUGE_H