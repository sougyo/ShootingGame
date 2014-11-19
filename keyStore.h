#ifndef ___KEY_STORE_H
#define ___KEY_STORE_H

#include <cassert>
#include <vector>
#include "keyStoreElement.h"

namespace gamesystem {
	class KeyStore;
}

class gamesystem::KeyStore {
private:
	std::vector<gamesystem::KeyStoreElement> keyStoreElements;
	
public:
	KeyStore(void);
	~KeyStore(void);
	KeyStore(const gamesystem::KeyStore&);
	gamesystem::KeyStore& operator=(const gamesystem::KeyStore&);
	
public:
	void addKeyStoreElement(bool, bool, bool, bool, bool, bool, bool, bool, bool);
	void addKeyStoreElement(gamesystem::KeyStoreElement&);
	gamesystem::KeyStoreElement& getKeyStoreElement(int);
	inline int getSize(void) const { return static_cast<int>(keyStoreElements.size()); }
};

#endif // ___KEY_STORE_H