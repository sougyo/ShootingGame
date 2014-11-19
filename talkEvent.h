#ifndef ___TALK_EVENT_H
#define ___TALK_EVENT_H

#include <cassert>
#include <vector>
#include "keyStoreElement.h"
#include "talkEventElement.h"
#include "gameInformation.h"
#include "Image.h"
#include "Font.h"
#include "FontFactory.h"

namespace talkeventutil {
	class TalkEvent;
}

class talkeventutil::TalkEvent {
private:
	graphics::Image* leftActiveImage;
	graphics::Image* leftInactiveImage;
	graphics::Image* rightActiveImage;
	graphics::Image* rightInactiveImage;
	gamesystem::KeyStoreElement prevKeyStoreElement;
	gamesystem::KeyStoreElement currentKeyStoreElement;
	font::Font* fontA;
	
private:
	std::vector<talkeventutil::TalkEventElement> talkEventElements;
	bool isActive_;
	int index;
	
private:
	TalkEvent(const talkeventutil::TalkEvent&);
	const talkeventutil::TalkEvent& operator=(const talkeventutil::TalkEvent&);
	
public:
	TalkEvent(graphics::Image*, graphics::Image*, graphics::Image*, graphics::Image*);
	~TalkEvent(void);
	
public:
	void addTalkEventElement(talkeventutil::TalkEventElement);
	void fire(int, int);
	void move(void);
	void draw(void);
	void setKeyData(gamesystem::KeyStoreElement);
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) const { return static_cast<int>(talkEventElements.size()); }

private:
	inline bool isShotPushed(void) const { return !prevKeyStoreElement.isShot() && currentKeyStoreElement.isShot(); }
};

#endif // ___TALE_EVENT_H
