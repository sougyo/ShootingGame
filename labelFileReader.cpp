#include "labelFileReader.h"

using std::string;
using gameutil::FileReader;
using labelIO::LabelFile;
using labelIO::LabelFileReader;

LabelFileReader::LabelFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

LabelFileReader::~LabelFileReader(void) {
}

LabelFile* LabelFileReader::createLabelFile(void) {
	string imageStr = readLine();
	assert(!imageStr.find("Image:"));
	imageStr = imageStr.substr(6);
	
	string isStr = readLine();
	assert(!isStr.find("IS:"));
	isStr = isStr.substr(3);
	
	string mpStr = analyzeMovePatternString();
	
	LabelFile* labelFile = new LabelFile(imageStr, isStr, mpStr);
	
	return labelFile;
}

string LabelFileReader::analyzeMovePatternString(void) {
	string temp = readLine();
	assert(!temp.find("MP{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}