#ifndef ___KEY_STORE_FILE_WRITER_H
#define ___KEY_STORE_FILE_WRITER_H

#include <cassert>
#include <string>
#include <sstream>
#include "fileWriter.h"
#include "keyStoreFile.h"

namespace gamesystemIO {
	class KeyStoreFileWriter;
}

class gamesystemIO::KeyStoreFileWriter : public gameutil::FileWriter {
private:
	KeyStoreFileWriter(const gamesystemIO::KeyStoreFileWriter&);
	const gamesystemIO::KeyStoreFileWriter& operator=(const gamesystemIO::KeyStoreFileWriter&);
	
public:
	KeyStoreFileWriter(std::string);
	~KeyStoreFileWriter(void);
	
public:
	void write(gamesystemIO::KeyStoreFile&);
};


#endif // ___KEY_STORE_FILE_WRITER_H