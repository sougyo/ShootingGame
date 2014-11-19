#ifndef ___MISSILE_ELEMENT_H
#define ___MISSILE_ELEMENT_H

#include "gamefwd.h"
#include "missileDeclaration.h"
#include "moveable.h"
#include "missile.h"

namespace missileElement {
    struct InitialState {
        double x;
        double y;
        double vr;
        double vtheta;
        int time;
    };
}

class missileutil::MissileElement : public gameutil::Moveable {
public:
    static gamesystem::Fighter* fighter;
    
private:
    missileElement::InitialState initialState;

private:
    missileutil::Missile* owner;
    
private:
    MissileElement(const missileutil::MissileElement&);
    const missileutil::MissileElement& operator=(const missileutil::MissileElement&);
    
public:
    MissileElement(missileutil::Missile*, double, double, double, double, int);
    ~MissileElement(void);
    
    void fire(void);
    void move(void);
    void draw(void);
    void toInactive(void);
    
public:
    static int count;
};

#endif // ___MISSILE_ELEMENT_H
