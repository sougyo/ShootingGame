#ifndef ___KEY_STORE_FILE_H
#define ___KEY_STORE_FILE_H

#include <string>
#include "keyStore.h"
#include "gameInformation.h"

namespace gamesystemIO {
	class KeyStoreFile;
}

class gamesystemIO::KeyStoreFile {
private:
	int stageNo;
	gamesystem::GameInformation::StageType stageType;
	gamesystem::GameInformation::PlayerType playerType;
	std::string name;
	gamesystem::KeyStore keyStore;
	
private:
	KeyStoreFile(const gamesystemIO::KeyStoreFile&);
	const gamesystemIO::KeyStoreFile& operator=(const gamesystemIO::KeyStoreFile&);

public:
	KeyStoreFile(int, gamesystem::GameInformation::StageType, gamesystem::GameInformation::PlayerType, std::string, gamesystem::KeyStore);
	~KeyStoreFile(void);
	
public:
	inline int getStageNo(void) const { return stageNo; }
	inline gamesystem::GameInformation::StageType getStageType(void) const { return stageType; }
	inline gamesystem::GameInformation::PlayerType getPlayerType(void) const { return playerType; }
	inline std::string getName(void) const { return name; }
	inline gamesystem::KeyStore getKeyStore(void) { return keyStore; }
};

#endif // ___KEY_STORE_FILE_H
