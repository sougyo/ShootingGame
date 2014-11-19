#ifndef ___MISSILE_SET_FACTORY_H
#define ___MISSILE_SET_FACTORY_H

#include <algorithm>
#include <string>
#include <sstream>
#include "missileDeclaration.h"
#include "constantField.h"
#include "image.h"
#include "imageFactory.h"
#include "missileFile.h"
#include "missileFileElement.h"
#include "missile.h"
#include "missileSet.h"
#include "movePattern.h"
#include "movePatternFactory.h"

class factory::MissileSetFactory {
private:
	MissileSetFactory(const factory::MissileSetFactory&);
	const factory::MissileSetFactory& operator=(const factory::MissileSetFactory&);
	
public:
	MissileSetFactory(void);
	~MissileSetFactory(void);
	
public:
	missileutil::MissileSet* createMissileSet(const missileIO::MissileFile*);
	
private:
	missileutil::Missile* createMissile(const missileIO::MissileFileElement*, int);
	void analyzeInitialState(std::string, missileutil::Missile*, int, int);
	int getMissileSize(std::string, int, int);
};

#endif // ___MISSILE_SET_FACTORY_H
