#include "keyStoreFileWriter.h"

using std::string;
using std::ostringstream;
using gameutil::FileWriter;
using gamesystem::KeyStore;
using gamesystem::KeyStoreElement;
using gamesystemIO::KeyStoreFileWriter;
using gamesystemIO::KeyStoreFile;


KeyStoreFileWriter::KeyStoreFileWriter(string fileName) : FileWriter(fileName) {
}

KeyStoreFileWriter::~KeyStoreFileWriter(void) {
}

void KeyStoreFileWriter::write(KeyStoreFile& keyStoreFile) {
	ostringstream out;

	out << keyStoreFile.getStageNo() << ' ';
	out << keyStoreFile.getStageType() << ' ';
	out << keyStoreFile.getPlayerType();
	out << "\n";
	out << "NAME:" + keyStoreFile.getName() + "\n";
	
	KeyStore keyStore = keyStoreFile.getKeyStore();
	for (int i = 0; i < keyStore.getSize(); i++)
		out << keyStore.getKeyStoreElement(i).getUChar();
		
	FileWriter::write(out.str());
}
