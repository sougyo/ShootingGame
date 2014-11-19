#ifndef ___KEY_STORE_ELEMENT_H
#define ___KEY_STORE_ELEMENT_H

#include <vector>

namespace gamesystem {
	class KeyStoreElement;
}

class gamesystem::KeyStoreElement {
private:
	bool up;
	bool down;
	bool left;
	bool right;
    bool shot;
    bool bomb;
    bool slow;
    bool skip;
    bool pause;

public:
	KeyStoreElement(bool, bool, bool, bool, bool, bool, bool, bool, bool);
	explicit KeyStoreElement(unsigned char);
	~KeyStoreElement(void);
	
public:
	inline bool isUp	(void) const { return up; }
	inline bool isDown	(void) const { return down; }
	inline bool isLeft	(void) const { return left; }
	inline bool isRight	(void) const { return right; }
	inline bool isShot	(void) const { return shot; }
	inline bool isBomb	(void) const { return bomb; }
	inline bool isSlow	(void) const { return slow; }
	inline bool isSkip	(void) const { return skip; }
	inline bool isPause	(void) const { return pause; }
	
public:
	unsigned char getUChar(void) const;
};



#endif // ___KEY_STORE_ELEMENT_H
