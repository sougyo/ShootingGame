#ifndef ___LABEL_MOVE_PATTERN_H
#define ___LABEL_MOVE_PATTERN_H

#include <cassert>
#include <vector>
#include "angle.h"
#include "gameMath.h"

namespace labelutil {
	class LabelMovePattern;
	struct LabelMovePatternElement;
}

struct labelutil::LabelMovePatternElement {
	double ar;
	double atheta;
	double aphi;
	labelutil::Angle aangle;
	int time;
};

class labelutil::LabelMovePattern {
private:
	int index;
	bool isActive_;
	
private:
	std::vector<int> initTime;
	std::vector<labelutil::LabelMovePatternElement> labelMovePatternElements;
	
private:
	LabelMovePattern(const labelutil::LabelMovePattern&);
	const labelutil::LabelMovePattern& operator=(const labelutil::LabelMovePattern&);
	
public:
	LabelMovePattern(void);
	~LabelMovePattern(void);

public:
	void addLabelMovePatternElement(double, double, double, double, double, double , int);
	void move(double&, double&, double&, labelutil::Angle&);
	void initialize(void);
	inline int getSize(void) const { return static_cast<int>(labelMovePatternElements.size()); }
	inline bool isActive(void) const { return isActive_; }
};

#endif // ___LABEL_MOVE_PATTERN_H 