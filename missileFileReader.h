#ifndef ___MISSILE_FILE_READER_H
#define ___MISSILE_FILE_READER_H

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include "missileDeclaration.h"
#include "missileFile.h"
#include "fileReader.h"

class missileIO::MissileFileReader : public gameutil::FileReader {
private:
	MissileFileReader(const missileIO::MissileFileReader&);
	const missileIO::MissileFileReader& operator=(const missileIO::MissileFileReader&);

private:
	explicit MissileFileReader(const char*);

public:
	MissileFileReader(const char*, const char*);
	~MissileFileReader(void);
	
public:
	missileIO::MissileFile* createMissileFile(void);
	
private:
	int analyzeInterval(void);
	std::string analyzeImageFileName(void);
	std::string analyzeInitialStateString(void);
	std::string analyzeMovePatternString(void);
};

#endif // ___MISSILE_FILE_READER_H