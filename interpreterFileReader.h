#ifndef ___INTERPRETER_FILE_READER_H
#define ___INTERPRETER_FILE_READER_H

#include <cassert>
#include <fstream>
#include "interpreterFile.h"
#include "fileReader.h"

namespace interpreterIO {
	class InterpreterFileReader;
}

class interpreterIO::InterpreterFileReader : public gameutil::FileReader {
private:
	InterpreterFileReader(const interpreterIO::InterpreterFileReader&);
	const interpreterIO::InterpreterFileReader operator=(const interpreterIO::InterpreterFileReader&);
	
private:
	explicit InterpreterFileReader(const char*);
	
public:
	InterpreterFileReader(const char*, const char*);
	~InterpreterFileReader(void);
	
public:
	interpreterIO::InterpreterFile* createInterpreterFile(void);
};

#endif // ___INTERPRETER_FILE_READER_H