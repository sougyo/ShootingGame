#ifndef ___TITLE_POOL_ELEMENT_H
#define ___TITLE_POOL_ELEMENT_H

#include "label.h"
#include "poolElement.h"
#include "table.h"

namespace titleutil {
	class TitlePoolElement;
}

class titleutil::TitlePoolElement : public gameutil::PoolElement {
public:
	static gameutil::Table<labelutil::Label>* labelTable;

private:
	labelutil::Label* label;
	int x;
	int y;
	
private:
	TitlePoolElement(const titleutil::TitlePoolElement&);
	const titleutil::TitlePoolElement& operator=(const titleutil::TitlePoolElement&);
	
public:
	TitlePoolElement(labelutil::Label*, int, int, int);
	~TitlePoolElement(void);

public:
	void execute(void);
	bool isActive(void);
};

#endif //___TITLE_POOL_ELEMENT_H