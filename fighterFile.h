#ifndef ___FIGHTER_FILE_H
#define ___FIGHTER_FILE_H

#include <string>
namespace gamesystemIO {
    class FighterFile;
}

class gamesystemIO::FighterFile {
private:
    int radius;
    double highSpeed;
    double slowSpeed;
    std::string imageFileName;
    std::string missileFileName;
    
private:
    FighterFile(const gamesystemIO::FighterFile&);
    const gamesystemIO::FighterFile& operator=(const gamesystemIO::FighterFile&);
    
public:
    FighterFile(int radius, double, double, std::string, std::string);
    ~FighterFile(void);
    
public:
    inline int getRadius(void) const { return radius; }
    inline double getHighSpeed(void) const { return highSpeed; }
    inline double getSlowSpeed(void) const { return slowSpeed; }
    inline std::string getImageFileName(void) const { return imageFileName; }
    inline std::string getMissileFileName(void) const { return missileFileName; }
};

#endif // ___FIGHTER_FILE_H
