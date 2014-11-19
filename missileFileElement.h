#ifndef ___MISSILE_FILE_ELEMENT_H
#define ___MISSILE_FILE_ELEMENT_H

#include <string>
#include "missileDeclaration.h"

class missileIO::MissileFileElement {
private:
	int interval;
	std::string imageFileName;
	std::string initialStateString;
	std::string movePatternString;
	
private:
	MissileFileElement(const missileIO::MissileFileElement&);
	const missileIO::MissileFileElement& operator=(const missileIO::MissileFileElement&);
	
public:
	MissileFileElement(int, std::string, std::string, std::string);
	~MissileFileElement(void);

public:
	inline const int getInterval(void) const { return interval; }
	inline const std::string& getImageFileName(void) const { return imageFileName; }
	inline const std::string& getInitialStateString(void) const { return initialStateString; }
	inline const std::string& getMovePatternString(void) const { return movePatternString; }
};

#endif // ___MISSILE_FILE_ELEMENT_H