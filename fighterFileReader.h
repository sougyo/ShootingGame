#ifndef ___FIGHTER_FILE_READER_H
#define ___FIGHTER_FILE_READER_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "constantField.h"
#include "fileReader.h"
#include "fighterFile.h"

namespace gamesystemIO {
	class FighterFileReader;
}

class gamesystemIO::FighterFileReader : public gameutil::FileReader {
private:
	std::string fighterName;

private:
	FighterFileReader(const gamesystemIO::FighterFileReader&);
	const gamesystemIO::FighterFileReader& operator=(const gamesystemIO::FighterFileReader&);
	
public:
	explicit FighterFileReader(std::string);
	~FighterFileReader(void);
	
public:
	gamesystemIO::FighterFile* createFighterFile(void);
};

#endif // ___FIGHTER_FILE_READER_H