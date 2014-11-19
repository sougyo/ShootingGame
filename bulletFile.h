#ifndef ___BULLET_FILE_H
#define ___BULLET_FILE_H

#include <cassert>
#include <string>
#include <vector>
#include "bulletFileElement.h"

namespace bulletIO {
	class BulletFile;
}

class bulletIO::BulletFile {
private:
	std::vector<bulletIO::BulletFileElement> bulletFileElements;

private:
	BulletFile(const bulletIO::BulletFile&);
	bulletIO::BulletFile& operator=(const bulletIO::BulletFile&);

public:
	BulletFile(void);
	~BulletFile(void);
	
public:
	void addBulletFileElement(bulletIO::BulletFileElement);
	const bulletIO::BulletFileElement* getBulletFileElement(int) const;
	const bulletIO::BulletFileElement* searchBulletFileElement(std::string) const;
	inline int getSize(void) const { return static_cast<int>(bulletFileElements.size()); }
	void dump(void); // デバッグ用
};

#endif // ___BULLET_FILE_H