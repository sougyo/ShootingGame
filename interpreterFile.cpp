#include "interpreterFile.h"

using std::string;
using interpreterIO::InterpreterFile;

InterpreterFile::InterpreterFile(string efStr, string itStr) {
	this->enemyFilesString = efStr;
	this->interpreterString = itStr;
}

InterpreterFile::~InterpreterFile(void) {
}

string InterpreterFile::getEnemyFilesString(void) const {
	return enemyFilesString;
}

string InterpreterFile::getInterpreterString(void) const {
	return interpreterString;
}