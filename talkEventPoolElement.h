#ifndef ___TALK_EVENT_POOL_ELEMENT_H
#define ___TALK_EVENT_POOL_ELEMENT_H

#include "effectPool.h"
#include "poolElement.h"
#include "talkEvent.h"
#include "table.h"
#include "enemy.h"

namespace talkeventutil {
	class TalkEventPoolElement;
}

class talkeventutil::TalkEventPoolElement : public gameutil::PoolElement {
public:
	static gameutil::Table<talkeventutil::TalkEvent>* talkEventTable;
	static gameutil::Table<enemyutil::Enemy>* enemyTable;
	static gameutil::Table<bulletutil::Bullet>* bulletTable;
	static effectutil::EffectPool* clearEffectPool;

private:
	talkeventutil::TalkEvent* talkEvent;
	
private:
	TalkEventPoolElement(const talkeventutil::TalkEventPoolElement&);
	const talkeventutil::TalkEventPoolElement& operator=(const talkeventutil::TalkEventPoolElement&);
	
public:
	TalkEventPoolElement(talkeventutil::TalkEvent*, int);
	~TalkEventPoolElement(void);
	
public:
	void execute(void);
	bool isActive(void);
};

#endif // ___TALK_EVENT_POOL_ELEMENT_H