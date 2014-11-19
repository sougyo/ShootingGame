#include "fileWriter.h"

using std::fstream;
using std::istringstream;
using std::string;
using gameutil::FileWriter;
using gameutil::Random;

FileWriter::FileWriter(string fileName) {
    this->fileName = fileName;
}

FileWriter::~FileWriter(void) {
}

void FileWriter::write(string str) {
    encrypt(str);
}
    
void FileWriter::encrypt(string& str) {
    fstream out(fileName.c_str(), std::ios::out | std::ios::binary);
    assert(out.good());
    
    char c;
    Random random(28);
    istringstream in(str);
    int count = 0;

    in.get(c);
    while (!in.eof()) {
        out.put(static_cast<char>(static_cast<unsigned char>(c) ^ random.rand()));
        if (count % 6 == 0)
            c = static_cast<char>(count*17);
        else
            in.get(c);
        count++;
    }

}
