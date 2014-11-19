#ifndef ___TALK_EVENT_ELEMENT_H
#define ___TALK_EVENT_ELEMENT_H

#include <string>
#include <algorithm>
#include "constantField.h"

namespace talkeventutil {
	class TalkEventElement;

	namespace pasitiontype {
		const int LEFT = 0;
		const int RIGHT = 1;
		const int NONE = 2;
		const int ALONE = 3;
	}
}

class talkeventutil::TalkEventElement {
private:
	int position;
	std::string message;

public:
	TalkEventElement(std::string, int);
	~TalkEventElement(void);
	
	
public:
	inline int getPosition(void) const { return position; }
	inline std::string getMessage(void) const { return message; }
};

#endif //___TALK_EVENT_ELEMENT_H