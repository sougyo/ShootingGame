#ifndef ___KEY_STORE_FILE_READER_H
#define ___KEY_STORE_FILE_READER_H

#include <cassert>
#include <string>
#include "fileReader.h"
#include "keyStore.h"
#include "keyStoreFile.h"
#include "gameInformation.h"

namespace gamesystemIO {
    class KeyStoreFileReader;
}

class gamesystemIO::KeyStoreFileReader : public gameutil::FileReader {
private:
    KeyStoreFileReader(const gamesystemIO::KeyStoreFileReader&);
    const gamesystemIO::KeyStoreFileReader& operator=(const gamesystemIO::KeyStoreFileReader&);
    
public:
    KeyStoreFileReader(const char*);
    ~KeyStoreFileReader(void);
    
public:
    gamesystemIO::KeyStoreFile* createKeyStoreFile(void);
};

#endif // ___KEY_STORE_FILE_READER_H
