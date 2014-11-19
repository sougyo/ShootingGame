#ifndef ___TITLE_POOL_H
#define ___TITLE_POOL_H

#include "pool.h"

namespace titleutil {
	class TitlePool;
}

class titleutil::TitlePool : public gameutil::Pool {
private:
	TitlePool(const titleutil::TitlePool&);
	const titleutil::TitlePool& operator=(const titleutil::TitlePool&);

public:
	TitlePool(void);
	~TitlePool(void);
	
public:
	void move(void);
};

#endif // ___TITLE_POOL_H
