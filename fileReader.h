#ifndef ___FILE_READER_H
#define ___FILE_READER_H

#include <cassert>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "random.h"

namespace gameutil {
	class FileReader;
}

class gameutil::FileReader {
private:
	static std::string prevFileName;
	static std::string decryptedString;

protected:
	std::istringstream* in;
	
private:
	FileReader(const gameutil::FileReader&);
	const gameutil::FileReader& operator=(const gameutil::FileReader&);
	
public:
	explicit FileReader(const char*);
	FileReader(const char*, const char*);
	virtual ~FileReader(void);
	
public:
	std::string readLine(void);
	std::string readAll(void);
	
private:
	std::string decrypt(std::fstream&);
	
public:
	static int count; // デバッグ用
};

#endif // ___FILE_READER_H