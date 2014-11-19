#ifndef ___INTERPRETER_FILE_H
#define ___INTERPRETER_FILE_H

#include <string>

namespace interpreterIO {
	class InterpreterFile;
}

class interpreterIO::InterpreterFile {
private:
	std::string enemyFilesString;
	std::string interpreterString;
	
private:
	InterpreterFile(const interpreterIO::InterpreterFile&);
	const interpreterIO::InterpreterFile operator=(const interpreterIO::InterpreterFile&);
	
public:
	InterpreterFile(std::string, std::string);
	~InterpreterFile(void);

public:
	std::string getEnemyFilesString(void) const;
	std::string getInterpreterString(void) const;
};

#endif // ___INTERPRETER_FILE_H