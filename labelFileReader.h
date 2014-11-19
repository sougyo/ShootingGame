#ifndef ___LABEL_FILE_READER_H
#define ___LABEL_FILE_READER_H

#include <cassert>
#include <string>
#include "fileReader.h"
#include "labelFile.h"

namespace labelIO {
	class LabelFileReader;
}

class labelIO::LabelFileReader : public gameutil::FileReader {
private:
	LabelFileReader(const labelIO::LabelFileReader&);
	const labelIO::LabelFileReader& operator=(const labelIO::LabelFileReader&);

public:
	LabelFileReader(const char*, const char*);
	~LabelFileReader(void);
	
public:
	labelIO::LabelFile* createLabelFile(void);
	
private:
	std::string analyzeMovePatternString(void);
};

#endif ___LABEL_FILE_READER_H