#include "missileSetController.h"

using missileutil::MissileSetController;
using missileIO::MissileFile;
using missileIO::MissileFileReader;
using factory::MissileSetFactory;

MissileSetController::MissileSetController(MissileFile* missileFile, int size) : index(-1), count(0) {
    MissileSetFactory missileSetFactory;
    for (int i = 0; i < size; i++) {
        MissileSet* missileSet = missileSetFactory.createMissileSet(missileFile);
        missileSets.push_back(missileSet);
    }
}

MissileSetController::~MissileSetController(void) {
    for (int i = 0; i < getSize(); i++)
        delete missileSets[i];
}

void MissileSetController::fire(int power) {
    assert(getSize() > 0);
    if (count > 0)
        return;
    count = missileSets[0]->getTotalTime();
    for (int i = 0; i < getSize(); i++) {
        index = (index + 1) % getSize();
        if (!missileSets[index]->isActive()) {
            missileSets[index]->fire(power);
            break;
        }
    }
}

void MissileSetController::move(void) {
    count--;
}
