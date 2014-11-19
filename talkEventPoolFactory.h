#ifndef ___TALK_EVENT_POOL_FACTORY_H
#define ___TALK_EVENT_POOL_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "constantField.h"
#include "talkEvent.h"
#include "talkEventPool.h"
#include "talkEventPoolElement.h"
#include "talkEventFileReader.h"
#include "gameInformation.h"

namespace factory {
	class TalkEventPoolFactory;
}

class factory::TalkEventPoolFactory {
private:
	TalkEventPoolFactory(const factory::TalkEventPoolFactory&);
	const factory::TalkEventPoolFactory& operator=(const factory::TalkEventPoolFactory&);
	
public:
	TalkEventPoolFactory(void);
	~TalkEventPoolFactory(void);
	
public:
	talkeventutil::TalkEventPool* createTalkEventPool(std::string, gamesystem::GameInformation::PlayerType);
	
private:
	talkeventutil::TalkEvent* createTalkEvent(std::string, gamesystem::GameInformation::PlayerType);
};

#endif // ___TALK_EVENT_POOL_FACTORY_H