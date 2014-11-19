#ifndef ___LABEL_FACTORY_H
#define ___LABEL_FACTORY_H

#include <algorithm>
#include <string>
#include <sstream>
#include "constantField.h"
#include "label.h"
#include "labelMovePattern.h"
#include "labelFile.h"
#include "Image.h"
#include "ImageFactory.h"

namespace factory {
    class LabelFactory;
}

class factory::LabelFactory {
private:
    LabelFactory(const factory::LabelFactory&);
    const factory::LabelFactory& operator=(const factory::LabelFactory&);
    
public:
    ~LabelFactory(void);
    LabelFactory(void);
    
public:
    labelutil::Label* createLabel(const labelIO::LabelFile&);
    labelutil::Label* createLabel(const labelIO::LabelFile&, graphics::Image*);

private:
    labelutil::LabelMovePattern* createLabelMovePattern(std::string);
};

#endif // ___LABEL_FACTORY_H
