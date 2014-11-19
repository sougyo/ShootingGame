#ifndef ___MISSILE_FILE_H
#define ___MISSILE_FILE_H

#include <cassert>
#include <vector>
#include "missileDeclaration.h"
#include "missileFileElement.h"

class missileIO::MissileFile {
private:
	int totalTime;
	std::vector<missileIO::MissileFileElement*> missileFileElements;
	
private:
	MissileFile(const missileIO::MissileFile&);
	const missileIO::MissileFile& operator=(const missileIO::MissileFile&);
	
public:
	explicit MissileFile(int);
	~MissileFile(void);
	
public:
	void addMissileFileElement(missileIO::MissileFileElement*);
	const missileIO::MissileFileElement* getMissileFileElement(int) const;
	inline int getTotalTime(void) const { return totalTime; }
	inline int getSize(void) const { return static_cast<int>(missileFileElements.size()); }
};

#endif // ___MISSILE_FILE_H