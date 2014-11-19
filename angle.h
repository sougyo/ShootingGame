#ifndef ___ANGLE_H
#define ___ANGLE_H

namespace labelutil {
    class Angle;
}

class labelutil::Angle {
private:
    double xangle;
    double yangle;
    double zangle;
    
public:
    Angle(void);
    Angle(double, double, double);
    ~Angle(void);
    
    void setAngle(double, double, double);
    void addAngle(const labelutil::Angle&);
    
    inline double getXangle(void) const { return xangle; }
    inline double getYangle(void) const { return yangle; }
    inline double getZangle(void) const { return zangle; }
};

#endif // ___ANGLE_H
