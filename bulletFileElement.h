#ifndef ___BULLET_FILE_ELEMENT_H
#define ___BULLET_FILE_ELEMENT_H

#include <string>

namespace bulletIO {
	class BulletFileElement;
}

class bulletIO::BulletFileElement {
private:
	std::string bulletName;
	std::string imageFileName;
	std::string initialStateString;
	std::string movePatternString;
	
public:
	BulletFileElement(std::string, std::string, std::string, std::string);
	BulletFileElement(const bulletIO::BulletFileElement&);
	~BulletFileElement(void);
	bulletIO::BulletFileElement& operator=(const bulletIO::BulletFileElement&);

public:
	inline const std::string& getBulletName(void) const { return bulletName; }
	inline const std::string& getImageFileName(void) const { return imageFileName; }
	inline const std::string& getInitialStateString(void) const { return initialStateString; }
	inline const std::string& getMovePatternString(void) const { return movePatternString; }
	
	static int count;
	void dump(void) const ;
};

#endif // ___BULLET_FILE_ELEMENT_H