#include "keyStoreFile.h"

using std::string;
using gamesystemIO::KeyStoreFile;
using gamesystem::GameInformation;
using gamesystem::KeyStore;

KeyStoreFile::KeyStoreFile(int stageNo, GameInformation::StageType stageType, GameInformation::PlayerType playerType, string name, KeyStore keyStore)
        : keyStore(keyStore) {
    this->stageNo = stageNo;
    this->stageType = stageType;
    this->playerType = playerType;
    this->name = name;
}

KeyStoreFile::~KeyStoreFile(void) {
}
