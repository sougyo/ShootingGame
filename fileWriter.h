#ifndef ___FILE_WRITER_H
#define ___FILE_WRITER_H

#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
#include "random.h"

namespace gameutil {
    class FileWriter;
}

class gameutil::FileWriter {
private:
    std::string fileName;
    
private:
    FileWriter(const gameutil::FileWriter&);
    const gameutil::FileWriter& operator=(const gameutil::FileWriter&);
    
public:
    FileWriter(std::string);
    ~FileWriter(void);
    
public:
    void write(std::string);
    
private:
    void encrypt(std::string&);

};

#endif // ___FILE_WRITER_H
