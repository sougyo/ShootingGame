#ifndef ___MISSILE_SET_CONTROLLER
#define ___MISSILE_SET_CONTROLLER

#include "missileDeclaration.h"
#include "missileFile.h"
#include "missileFileReader.h"
#include "missileSet.h"
#include "missileSetFactory.h"

class missileutil::MissileSetController {
private:
	int index;
	int count;
	std::vector<missileutil::MissileSet*> missileSets;
	
private:
	MissileSetController(const missileutil::MissileSetController&);
	const missileutil::MissileSetController& operator=(const missileutil::MissileSetController&);
	
public:
	MissileSetController(missileIO::MissileFile* missileFile, int);
	~MissileSetController(void);
	
public:
	void fire(int);
	void move(void);
	inline int getSize(void) const { return static_cast<int>(missileSets.size()); }
};

#endif // ___MISSILE_SET_CONTROLLER
