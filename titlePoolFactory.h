#ifndef ___TITLE_POOL_FACTORY_H
#define ___TITLE_POOL_FACTORY_H

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include "constantField.h"
#include "label.h"
#include "labelFileReader.h"
#include "labelFile.h"
#include "labelFactory.h"
#include "Image.h"
#include "ImageFactory.h"
#include "titlePool.h"
#include "titlePoolElement.h"

namespace factory {
	class TitlePoolFactory;
}

class factory::TitlePoolFactory {
private:
	TitlePoolFactory(const factory::TitlePoolFactory&);
	const factory::TitlePoolFactory& operator=(const factory::TitlePoolFactory&);
	
public:
	TitlePoolFactory(void);
	~TitlePoolFactory(void);
	
public:
	titleutil::TitlePool* createTitlePool(std::string);
	
private:
	labelutil::Label* createLabel(std::string, std::string);
};

#endif // ___TITLE_POOL_FACTORY_H