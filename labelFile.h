#ifndef ___LABEL_FILE_H
#define ___LABEL_FILE_H

#include <string>

namespace labelIO {
    class LabelFile;
}

class labelIO::LabelFile {
private:
    std::string imageFileName;
    std::string initialStateString;
    std::string movePatternString;
    
private:
    LabelFile(const labelIO::LabelFile&);
    const labelIO::LabelFile& operator=(const labelIO::LabelFile&);
    
public:
    LabelFile(std::string, std::string, std::string);
    ~LabelFile(void);
    
public:
    inline const std::string& getImageFileName(void) const { return imageFileName; }
    inline const std::string& getInitialStateString(void) const { return initialStateString; }
    inline const std::string& getMovePatternString(void) const { return movePatternString; }
};

#endif // ___LABEL_FILE_H
