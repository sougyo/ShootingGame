#ifndef ___MISSILE_SET_H
#define ___MISSILE_SET_H

#include <cassert>
#include <vector>
#include "constantField.h"
#include "missileDeclaration.h"
#include "missile.h"
#include "table.h"

class missileutil::MissileSet {
private:
	int totalTime;
	std::vector<missileutil::Missile*> missiles;
	
public:
	static gameutil::Table<missileutil::Missile>* missileTable;

private:
	MissileSet(const missileutil::MissileSet&);
	const missileutil::MissileSet& operator=(const missileutil::MissileSet&);

public:
	explicit MissileSet(int);
	~MissileSet(void);
	
public:
	void addMissile(missileutil::Missile*);
	void fire(int);
	missileutil::Missile* getMissile(int);
	bool isActive(void);
	inline int getTotalTime(void) const { return totalTime; }
	inline int getSize(void) const { return static_cast<int>(missiles.size()); }
};

#endif // ___MISSILE_SET_H
