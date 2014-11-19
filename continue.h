#ifndef ___CONTINUE_H
#define ___CONTINUE_H

#include "constantField.h"
#include "keyStoreElement.h"
#include "Image.h"
#include "ImageFactory.h"

namespace gamesystem{
	class Continue;
}

class gamesystem::Continue {
private:
	gamesystem::KeyStoreElement prevKeyStoreElement;
	gamesystem::KeyStoreElement currentKeyStoreElement;
	
	graphics::Image* yesImage1;
	graphics::Image* yesImage2;
	graphics::Image* noImage1;
	graphics::Image* noImage2;
	graphics::Image* titleImage;
	bool isYesState;
	bool isActive_;
	bool isContinue_;
	bool isNotContinue_;
	
private:
	Continue(const gamesystem::Continue&);
	const gamesystem::Continue& operator=(const gamesystem::Continue&);
	
public:
	Continue(void);
	~Continue(void);
	
public:
	void setKeyData(gamesystem::KeyStoreElement);
	void move(void);
	void draw(void);
	void show(void);
	inline bool isActive(void) const { return isActive_; }
	inline bool isContinue(void) const { return isContinue_; }
	inline bool isNotContinue(void) const { return isNotContinue_; }

	inline bool isShotPushed(void) const { return !prevKeyStoreElement.isShot() && currentKeyStoreElement.isShot(); }
	inline bool isRightPushed(void) const { return !prevKeyStoreElement.isRight() && currentKeyStoreElement.isRight(); }
	inline bool isLeftPushed(void) const { return !prevKeyStoreElement.isLeft() && currentKeyStoreElement.isLeft(); }
	inline bool isUpPushed(void) const { return !prevKeyStoreElement.isUp() && currentKeyStoreElement.isUp(); }
	inline bool isDownPushed(void) const { return !prevKeyStoreElement.isDown() && currentKeyStoreElement.isDown(); }

};

#endif // ___CONTINUE_H
