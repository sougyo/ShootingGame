#include "interpreterFileReader.h"

using std::string;
using interpreterIO::InterpreterFileReader;
using interpreterIO::InterpreterFile;
using gameutil::FileReader;

InterpreterFileReader::InterpreterFileReader(const char* filename) : FileReader(filename) {
}

InterpreterFileReader::InterpreterFileReader(const char* str1, const char* str2) : FileReader(str1, str2) {
}

InterpreterFileReader::~InterpreterFileReader() {
}

InterpreterFile* InterpreterFileReader::createInterpreterFile(void) {
	string temp;
	temp = readLine();
	assert( temp == "EnemyFiles{" );
	
	string enemyFilesString;
	while ( (temp = readLine()) != "}" )
		enemyFilesString.append(temp).append("\n");
	
	temp = readLine();
	assert(temp == "Interpreter{");
	
	string interpreterString;
	while ( (temp = readLine()) != "}" )
		interpreterString.append(temp).append("\n");
	
	return new InterpreterFile(enemyFilesString, interpreterString);
}
