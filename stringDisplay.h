#ifndef ___STRING_DISPLAY_H
#define ___STRING_DISPLAY_H

#include <cassert>
#include <string>
#include <sstream>
#include "constantField.h"
#include "Image.h"
#include "ImageFactory.h"

namespace gamesystem {
	class StringDisplay;
}

class gamesystem::StringDisplay {
private:
	static StringDisplay singleton;
	
private:
	std::string identChar;
	graphics::Image** activeImages;
	graphics::Image** inactiveImages;
	int imageWidth;
	int imageHeight;
	
private:
	StringDisplay(const gamesystem::StringDisplay&);
	const gamesystem::StringDisplay& operator=(const gamesystem::StringDisplay&);

public:
	StringDisplay(void);
	~StringDisplay(void);

public:
	static gamesystem::StringDisplay* getInstance(void) { return &singleton; }
	
public:
	void initialize(void);
	graphics::Image* getActiveImage(char);
	graphics::Image* getInactiveImage(char);
	void drawString(std::string, int, int);
	inline std::string getIdentChar(void) const { return identChar; }
};

#endif // ___STRING_DISPLAY_H