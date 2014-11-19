#include "effectFileReader.h"

using std::string;
using effectIO::EffectFile;
using effectIO::EffectFileReader;
using gameutil::FileReader;

EffectFileReader::EffectFileReader(const char* filename) : FileReader(filename) {	
}

EffectFileReader::EffectFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

EffectFileReader::~EffectFileReader(void) {
}

EffectFile* EffectFileReader::createEffectFile(void) {
	string temp = readLine();
	EffectFile* effectFile = new EffectFile;
	
	while (!temp.empty()) {
		assert(temp == "EffectImage{");
		string effectStr = analyzeEffectString();
		effectFile->addEffectElement(effectStr);
		temp = readLine();
	}
	
	return effectFile;
}

string EffectFileReader::analyzeEffectString(void) {
	string temp;
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}