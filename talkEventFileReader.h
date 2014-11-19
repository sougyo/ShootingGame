#ifndef ___TALK_EVENT_FILE_READER_H
#define ___TALK_EVENT_FILE_READER_H

#include <cassert>
#include <string>
#include "constantField.h"
#include "fileReader.h"
#include "talkEvent.h"
#include "Image.h"
#include "ImageFactory.h"

namespace talkeventutil {
	class TalkEventFileReader;
}

class talkeventutil::TalkEventFileReader : public gameutil::FileReader {
private:
	TalkEventFileReader(const talkeventutil::TalkEventFileReader&);
	const talkeventutil::TalkEventFileReader& operator=(const talkeventutil::TalkEventFileReader&);
	
public:
	TalkEventFileReader(const char*, const char*);
	~TalkEventFileReader(void);
	
public:
	talkeventutil::TalkEvent* createTalkEvent(void);
};

#endif //___TALK_EVENT_FILE_READER_H