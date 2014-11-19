#include "bulletFileReader.h"

using std::string;
using bulletIO::BulletFileReader;
using bulletIO::BulletFile;
using gameutil::FileReader;

BulletFileReader::BulletFileReader(const char* filename) : FileReader(filename) {
}

BulletFileReader::BulletFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

BulletFileReader::~BulletFileReader(void) {
}

BulletFile* BulletFileReader::createBulletFile(void) {
	string temp = readLine();
	assert(temp == string("FILESTART:"));
	
	BulletFile* bulletFile = new BulletFile();
	while (!in->eof()) {
		string temp = readLine();
		if (temp == "FILEEND:")
			break;
		if (temp == "MEMO:{") {
			ignoreMemoString();
			continue;
		}
		string name = analyzeBulletName(temp);
		string image = analyzeImageFileName();
		string is = analyzeInitialStateString();
		string mp = analyzeMovePatternString();
		
		BulletFileElement bfe(name, image, is, mp);
		bulletFile->addBulletFileElement(bfe);
	}
	return bulletFile;
}

string BulletFileReader::analyzeBulletName(string temp) {
	assert(!temp.find("Name:"));
	return temp.substr(5);
}

string BulletFileReader::analyzeImageFileName(void) {
	string temp = readLine();
	assert(!temp.find("Image:"));
	return temp.substr(6);
}

string BulletFileReader::analyzeInitialStateString(void) {
	string temp = readLine();
	assert(!temp.find("IS{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

string BulletFileReader::analyzeMovePatternString(void) {
	string temp = readLine();
	assert(!temp.find("MP{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

void BulletFileReader::ignoreMemoString(void) {
	while ( readLine() != ":}" ) ;
}
