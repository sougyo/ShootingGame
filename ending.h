#ifndef ___ENDING_H
#define ___ENDING_H

#include <string>
#include "constantField.h"
#include "label.h"
#include "fileReader.h"
#include "keyStoreElement.h"
#include "titlePool.h"
#include "titlePoolFactory.h"
#include "titlePoolElement.h"
#include "table.h"

namespace gamesystem {
	class Ending;
}

class gamesystem::Ending {
private:
	bool isActive_;
	gameutil::Table<labelutil::Label> labelTable;
	titleutil::TitlePool* titlePool;

private:
	Ending(const gamesystem::Ending&);
	const gamesystem::Ending& operator=(const gamesystem::Ending&);
	
public:
	Ending(const char*);
	~Ending(void);
	
public:
	void move(void);
	void draw(void);

	inline bool isActive(void) const { return isActive_; }
	
private:
	
};

#endif // ___ENDING