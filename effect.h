#ifndef ___EFFECT_H
#define ___EFFECT_H

#include <cassert>
#include "constantField.h"
#include "Image.h"

namespace effectutil {
	class Effect;
}

class effectutil::Effect {
private:
	int maxSize;
	int size;
	int x;
	int y;
	int time;
	bool isActive_;
	graphics::Image** images;

private:
	Effect(const effectutil::Effect&);
	const effectutil::Effect& operator=(const effectutil::Effect&);
	
public:
	explicit Effect(int);
	~Effect(void);
	
public:
	void addEffectImage(graphics::Image*);
	void fire(int, int);
	void move(void);
	void draw(void);
	bool isOutOfDisplay(int, int);
	inline void clean(void) { isActive_ = false; }
	inline bool isActive(void) const { return isActive_; }
	
public:
	static int count;
};

#endif // ___EFFECT_H
