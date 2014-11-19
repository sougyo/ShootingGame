#ifndef ___LASER_H
#define ___LASER_H

#include "moveable.h"

namespace bulletutil {
	class Lazer;
}

class bulletutil::Lazer {
private:
	Lazer(const bulletutil::Lazer&);
	const bulletutil::Lazer& operator=(const bulletutil::Lazer&);

public:
	Lazer(void);
	~Lazer(void);
};

#endif // ___LASER_H