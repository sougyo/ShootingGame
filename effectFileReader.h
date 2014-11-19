#ifndef ___EFFECT_FILE_READER_H
#define ___EFFECT_FILE_READER_H

#include <cassert>
#include <fstream>
#include "effectFile.h"
#include "fileReader.h"

namespace effectIO {
	class EffectFileReader;
}

class effectIO::EffectFileReader : public gameutil::FileReader {
private:
	EffectFileReader(const effectIO::EffectFileReader&);
	const effectIO::EffectFileReader& operator=(const effectIO::EffectFileReader&);

private:
	explicit EffectFileReader(const char*);

public:
	EffectFileReader(const char*, const char*);
	~EffectFileReader(void);
	
public:
	effectIO::EffectFile* createEffectFile(void);
	
private:
	std::string analyzeEffectString(void);
};

#endif // ___EFFECT_FILE_READER_H
