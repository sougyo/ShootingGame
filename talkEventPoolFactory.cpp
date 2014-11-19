#include "talkEventPoolFactory.h"

using std::string;
using std::count;
using std::replace;
using std::istringstream;
using std::ostringstream;
using talkeventutil::TalkEvent;
using talkeventutil::TalkEventPool;
using talkeventutil::TalkEventPoolElement;
using talkeventutil::TalkEventFileReader;
using factory::TalkEventPoolFactory;
using gamesystem::GameInformation;

TalkEventPoolFactory::TalkEventPoolFactory(void) {
}

TalkEventPoolFactory::~TalkEventPoolFactory(void) {
}

TalkEventPool* TalkEventPoolFactory::createTalkEventPool(string str, GameInformation::PlayerType playerType) {
    TalkEventPool* talkEventPool = new TalkEventPool;
    
    int line = static_cast<int>(count(str.begin(), str.end(), '\n'));
    replace(str.begin(), str.end(), ',', ' ');
    assert(line == count(str.begin(), str.end(), ' '));
    istringstream in(str);
    
    string fileName;
    int time;
    for (int i = 0; i < line; i++) {
        in >> fileName;
        in >> time;
        talkEventPool->addPoolElement(new TalkEventPoolElement(createTalkEvent(fileName, playerType), time));
    }
    
    return talkEventPool;
}
    
TalkEvent* TalkEventPoolFactory::createTalkEvent(string fileName, GameInformation::PlayerType playerType) {
    ostringstream out;
    out << playerType << fileName;
    fileName = out.str();

    TalkEventFileReader talkEventFileReader(gameutil::DATA_PATH.c_str(), fileName.c_str());
    TalkEvent* talkEvent = talkEventFileReader.createTalkEvent();
    return talkEvent;
}
