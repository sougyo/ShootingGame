#ifndef ___SCORE_FILE_WRITER_H
#define ___SCORE_FILE_WRITER_H

#include <string>
#include <sstream>
#include "fileWriter.h"
#include "scoreFile.h"
#include "gameInformation.h"
#include "constantField.h"

namespace gamesystemIO {
	class ScoreFileWriter;
}

class gamesystemIO::ScoreFileWriter : public gameutil::FileWriter {
private:
	ScoreFileWriter(const gamesystemIO::ScoreFileWriter&);
	const gamesystemIO::ScoreFileWriter& operator=(const gamesystemIO::ScoreFileWriter&);

public:
	ScoreFileWriter(const char*);
	~ScoreFileWriter(void);
	
public:
	void write(gamesystemIO::ScoreFile&);
};

#endif // ___SCORE_FILE_WRITER_H
