#ifndef ___EFFECT_POOL_H
#define ___EFFECT_POOL_H

#include <vector>
#include <string>
#include "effect.h"
#include "effectFactory.h"
#include "table.h"

namespace effectutil {
	class EffectPool;
}

class effectutil::EffectPool {
public:
	static gameutil::Table<effectutil::Effect>* effectTable;

public:
	static gameutil::Table<effectutil::Effect>* getEffectTable(void) { return effectTable; }
	
private:
	std::vector<effectutil::Effect*> effects;
	
private:
	EffectPool(const effectutil::EffectPool&);
	const effectutil::EffectPool& operator=(const effectutil::EffectPool&);
	
public:
	EffectPool(int, std::string);
	~EffectPool(void);
	
public:
	void fire(int, int);
	void clean(void);
	inline int getSize(void) const { return static_cast<int>(effects.size()); }
};

#endif // ___EFFECT_POOL_H