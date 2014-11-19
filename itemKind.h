#ifndef ___ITEM_KIND_H
#define ___ITEM_KIND_H

#include "gamefwd.h"
#include "image.h"
#include "gameInformation.h"

class itemutil::ItemKind {
public:
	static gamesystem::GameInformation* gameInformation;
	
private:
	char kind;
	void (*func)(gamesystem::GameInformation&, itemutil::ItemElement*);
	graphics::Image* image1;
	graphics::Image* image2;
	
private:
	ItemKind(const itemutil::ItemKind&);
	const itemutil::ItemKind& operator=(const itemutil::ItemKind&);
	
public:
	ItemKind(char, void (*func)(gamesystem::GameInformation&, itemutil::ItemElement*), graphics::Image*, graphics::Image*);
	~ItemKind(void);
	
public:
	void caughtProcess(itemutil::ItemElement*) const ;
	graphics::Image* getImage(void) const;
	inline char getKindChar(void) const { return kind; }

};

#endif // ___ITEM_KIND_H
