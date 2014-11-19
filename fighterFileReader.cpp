#include "fighterFileReader.h"

using std::istringstream;
using std::string;
using gameutil::FileReader;
using gamesystemIO::FighterFile;
using gamesystemIO::FighterFileReader;

FighterFileReader::FighterFileReader(string fighterName)
		: FileReader(gameutil::DATA_PATH.c_str(), gameutil::FIGHTERFILE_PATH.c_str()) {
	this->fighterName = fighterName;
}

FighterFileReader::~FighterFileReader(void) {
}

FighterFile* FighterFileReader::createFighterFile(void) {
	string temp = readLine();
	while (temp != fighterName) {
		assert(!in->eof());
		temp = readLine();
	}
	temp = readLine();
	assert(static_cast<int>(std::count(temp.begin(), temp.end(), ' ')) == 4);
	istringstream fighterin(temp);
	
	int radius;
	double highSpeed;
	double slowSpeed;
	string imageFileName;
	string missileFileName;

	fighterin >> radius >> highSpeed >> slowSpeed >> imageFileName >> missileFileName;
	
	FighterFile* fighterFile = new FighterFile(radius, highSpeed, slowSpeed, imageFileName, missileFileName);
	return fighterFile;
}