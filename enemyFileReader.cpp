#include "enemyFileReader.h"

using std::string;
using bulletIO::BulletFile;
using bulletIO::BulletFileReader;
using enemyIO::EnemyFile;
using enemyIO::EnemyFileElement;
using enemyIO::EnemyFileReader;
using gameutil::FileReader;

EnemyFileReader::EnemyFileReader(const char* filename) : FileReader(filename) {
}

EnemyFileReader::EnemyFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

EnemyFileReader::~EnemyFileReader(void) {
}

EnemyFile* EnemyFileReader::createEnemyFile(void) {
	string temp = readLine();
	assert(temp == string("FILESTART:"));
	
	BulletFile* bulletFile = analyzeBulletFile();
	
	EnemyFile* enemyFile = new EnemyFile(bulletFile);
	while (!in->eof()) {
		string temp = readLine();
		if (temp == "FILEEND:")
			break;
		string name		= analyzeEnemyName(temp);
		string image	= analyzeImageFileName();
		bool collision	= analyzeCanCollision();
		int hp	= analyzeHp();
		string is = analyzeInitialStateString();
		string mp = analyzeMovePatternString();
		string bp = analyzeBulletPatternString();
		string ip = analyzeImagePatternString();
		string op = analyzeOptionPatternString();
		ignoreMemoString();
		
		EnemyFileElement efe(name, image, hp, collision, is, mp, bp, ip, op);
		enemyFile->addEnemyFileElement(efe);
	}
	return enemyFile;
}

BulletFile* EnemyFileReader::analyzeBulletFile(void) {
	string temp = readLine();
	assert(!temp.find("Bullet:"));
	string bulletFileName = temp.substr(7);
	BulletFileReader bulletFileReader(gameutil::DATA_PATH.c_str(), bulletFileName.c_str());
	return bulletFileReader.createBulletFile();
}

int EnemyFileReader::analyzeHp(void) {
	string temp = readLine();
	assert(!temp.find("HP:"));
	return std::atoi(temp.substr(3).c_str());
}
bool EnemyFileReader::analyzeCanCollision(void) {
	string temp = readLine();
	assert(!temp.find("Attacked:"));
	string result = temp.substr(9);
	if (result == "true")
		return true;
	else
		return false;
}
	
string EnemyFileReader::analyzeEnemyName(string temp) {
	assert(!temp.find("Name:"));
	return temp.substr(5);
}

string EnemyFileReader::analyzeImageFileName(void) {
	string temp = readLine();
	assert(!temp.find("Image:"));
	return temp.substr(6);
}

string EnemyFileReader::analyzeInitialStateString(void) {
	string temp = readLine();
	assert(!temp.find("IS{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

string EnemyFileReader::analyzeMovePatternString(void) {
	string temp = readLine();
	assert(!temp.find("MP{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

string EnemyFileReader::analyzeBulletPatternString(void) {
	string temp = readLine();
	assert(!temp.find("BP{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

string EnemyFileReader::analyzeImagePatternString(void) {
	string temp = readLine();
	assert(!temp.find("IM{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

string EnemyFileReader::analyzeOptionPatternString(void) {
	string temp = readLine();
	assert(!temp.find("OP{"));
	
	string buffer;
	while ( (temp = readLine()) != "}" )
		buffer.append(temp).append("\n");
	return buffer;
}

void EnemyFileReader::ignoreMemoString(void) {
	string temp = readLine();
	assert(!temp.find("MEMO:"));
	while ( readLine() != ":}" ) ;
}