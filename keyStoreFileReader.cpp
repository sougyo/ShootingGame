#include "keyStoreFileReader.h"

using std::string;
using gameutil::FileReader;
using gamesystem::KeyStore;
using gamesystem::KeyStoreElement;
using gamesystem::GameInformation;
using gamesystemIO::KeyStoreFile;
using gamesystemIO::KeyStoreFileReader;

KeyStoreFileReader::KeyStoreFileReader(const char* fileName) : FileReader(fileName) {
}

KeyStoreFileReader::~KeyStoreFileReader(void) {
}

KeyStoreFile* KeyStoreFileReader::createKeyStoreFile(void) {
	KeyStore keyStore;
	
	int stageNo;
	GameInformation::StageType stageType;
	GameInformation::PlayerType playerType;
	string name;
	
	(*in) >> stageNo >> stageType >> playerType >> name;
	
	if (static_cast<int>(name.find("NAME:")) != 0)
		return 0;
		
	name = name.substr(5);
	
	char temp;
	in->get(temp);
	in->get(temp);
	while (!in->eof()) {
		KeyStoreElement keyStoreElement(static_cast<unsigned char>(temp));
		keyStore.addKeyStoreElement(keyStoreElement);
		in->get(temp);
	}
	
	KeyStoreFile* keyStoreFile = new KeyStoreFile(stageNo, stageType, playerType, name, keyStore);
	return keyStoreFile;
}