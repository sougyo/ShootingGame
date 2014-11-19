#ifndef ___TALK_EVENT_POOL_H
#define ___TALK_EVENT_POOL_H

#include "pool.h"

namespace talkeventutil {
    class TalkEventPool;
}

class talkeventutil::TalkEventPool : public gameutil::Pool {
private:
    TalkEventPool(const talkeventutil::TalkEventPool&);
    const talkeventutil::TalkEventPool& operator=(const talkeventutil::TalkEventPool&);
    
public:
    TalkEventPool(void);
    ~TalkEventPool(void);
    
public:
    void move(void);
};

#endif // ___TALK_EVENT_POOL_H
