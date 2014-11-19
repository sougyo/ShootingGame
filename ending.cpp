#include "ending.h"

using std::string;
using gameutil::FileReader;
using gamesystem::Ending;
using factory::TitlePoolFactory;
using titleutil::TitlePool;
using titleutil::TitlePoolElement;

Ending::Ending(const char* fileName) : labelTable(50), isActive_(true) {
    TitlePoolElement::labelTable = &labelTable;
    FileReader fileReader(gameutil::DATA_PATH.c_str(), fileName);
    TitlePoolFactory titlePoolFactory;
    string temp = fileReader.readAll();
    while (true) {
        if (temp[temp.size() - 1] == '\n')
            temp.erase(temp.size() - 1, 1);
        else
            break;
    }
    temp += "\n";
    titlePool = titlePoolFactory.createTitlePool(temp);
    titlePool->start();
}

Ending::~Ending(void) {
    delete titlePool;
}

void Ending::move(void) {
    if (isActive_) {
        if (titlePool->isFinish()) {
            isActive_ = false;
            return;
        }
        titlePool->move();
        labelTable.move();
    }
}

void Ending::draw(void) {
    if (isActive_) {
        labelTable.draw();
    }
}

