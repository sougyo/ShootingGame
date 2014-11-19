#include "missileFileReader.h"

using std::string;
using std::strtol;
using missileIO::MissileFileReader;
using missileIO::MissileFile;
using missileIO::MissileFileElement;
using gameutil::FileReader;

MissileFileReader::MissileFileReader(const char* filename) : FileReader(filename) {
}

MissileFileReader::MissileFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

MissileFileReader::~MissileFileReader(void) {
}

MissileFile* MissileFileReader::createMissileFile(void) {
	string temp = readLine();
	assert(!temp.find("TotalTime:"));
	
	MissileFile* missileFile = new MissileFile(static_cast<int>(strtol(temp.substr(10).c_str(), 0, 10)));
	while (!in->eof()) {
		int interval = analyzeInterval();
		if (!interval)
			break;
		string image = analyzeImageFileName();
		string is = analyzeInitialStateString();
		string mp = analyzeMovePatternString();
		missileFile->addMissileFileElement(new MissileFileElement(interval, image, is, mp));
	}
	return missileFile;
}

int MissileFileReader::analyzeInterval(void) {
	string temp = readLine();
	if (temp.empty())
		return 0;
	assert(!temp.find("Interval:"));
	return static_cast<int>(strtol(temp.substr(9).c_str(), 0, 10));
}

string MissileFileReader::analyzeImageFileName(void) {
	string temp = readLine();
	assert(!temp.find("Image:"));
	return temp.substr(6);
}

string MissileFileReader::analyzeInitialStateString(void) {
	string temp = readLine();
	assert(!temp.find("IS{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

string MissileFileReader::analyzeMovePatternString(void) {
	string temp = readLine();
	assert(!temp.find("MP{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}