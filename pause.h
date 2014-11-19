#ifndef ___PAUSE_H
#define ___PAUSE_H

#include <cassert>
#include "constantField.h"
#include "Image.h"
#include "ImageFactory.h"
#include "keyStoreElement.h"
#include "gameInformation.h"

namespace gamesystem {
	class Pause;
}

class gamesystem::Pause {
private:
	static const int INDEXMAX;
	
	bool isActive_;
	int index;
	int releaseCount;
	gamesystem::KeyStoreElement prevKeyStoreElement;
	gamesystem::KeyStoreElement currentKeyStoreElement;
	gamesystem::GameInformation* gameInformation;
	
	graphics::Image* cancelImage1;
	graphics::Image* cancelImage2;
	graphics::Image* restartImage1;
	graphics::Image* restartImage2;
	graphics::Image* quitImage1;
	graphics::Image* quitImage2;
	
private:
	Pause(const gamesystem::Pause&);
	const gamesystem::Pause& operator=(const gamesystem::Pause&);

public:
	explicit Pause(gamesystem::GameInformation*);
	~Pause(void);
	
public:
	void setKeyData(gamesystem::KeyStoreElement);
	void draw(void);
	void move(void);
	inline bool isActive(void) const { return isActive_; }
	
private:
	void releasePause(void) { releaseCount = 10; }

	inline bool isShotPushed(void)	const { return !prevKeyStoreElement.isShot() && currentKeyStoreElement.isShot(); }
	inline bool isBombPushed(void)	const { return !prevKeyStoreElement.isBomb() && currentKeyStoreElement.isBomb(); }
	inline bool isUpPushed(void)	const { return !prevKeyStoreElement.isUp() && currentKeyStoreElement.isUp(); }
	inline bool isDownPushed(void)	const { return !prevKeyStoreElement.isDown() && currentKeyStoreElement.isDown(); }
	inline bool isPausePushed(void)	const { return !prevKeyStoreElement.isPause() && currentKeyStoreElement.isPause(); }
};

#endif // ___PAUSE_H