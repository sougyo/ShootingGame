#include "poolSchedulerFactory.h"

using std::istringstream;
using std::string;
using bossutil::BossPool;
using enemyutil::EnemyPool;
using gameutil::Pool;
using gameutil::PoolScheduler;
using gamesystem::GameInformation;
using interpreterIO::InterpreterFile;
using titleutil::TitlePool;
using talkeventutil::TalkEventPool;
using namespace factory;


PoolSchedulerFactory::PoolSchedulerFactory(void) : in(0) {
}

PoolSchedulerFactory::~PoolSchedulerFactory(void) {
    assert(in != 0);
    delete in;
}

PoolScheduler* PoolSchedulerFactory::createPoolScheduler(const InterpreterFile& interpreterFile, const GameInformation& gameInformation) {
    assert(in == 0);
    in = new istringstream(interpreterFile.getInterpreterString());
    assert(*in);

    PoolScheduler* poolScheduler = new PoolScheduler;

    while (true) {
        string temp = readLine();
        if (temp == "")
            break;
        assert(!temp.find(":"));
        
        string opString = temp.substr(1, temp.size()-2);

        string buffer;
        temp = readLine();
        while (temp != "]") {
            buffer.append(temp).append("\n");
            temp = readLine();
        }
        if (opString == "enemy")
            poolScheduler->addPool(createEnemyPool(interpreterFile.getEnemyFilesString(), buffer));
        else {
            poolScheduler->addPool(createPool(opString, buffer, gameInformation));
        }
    }
    return poolScheduler;
}

string PoolSchedulerFactory::readLine(void) {
    assert(!in->eof());
    const int TEMPSIZE = 2000;
    char temp[TEMPSIZE];
    in->getline(temp, TEMPSIZE);
    return static_cast<string>(temp);
}

Pool* PoolSchedulerFactory::createEnemyPool(string enemyFilesString, string& interpreterString) {
    EnemyPool* enemyPool;
    EnemyPoolFactory enemyPoolFactory;
    enemyPool = enemyPoolFactory.createEnemyPool(enemyFilesString, interpreterString);
    return enemyPool;
}

Pool* PoolSchedulerFactory::createPool(string& opString, string& interpreterString, const GameInformation& gameInformation) {
    if (opString == "boss") {
        BossPool* bossPool;
        BossPoolFactory bossPoolFactory;
        bossPool = bossPoolFactory.createBossPool(interpreterString);
        return bossPool;
    } else if (opString == "title") {
        TitlePool* titlePool;
        TitlePoolFactory titlePoolFactory;
        titlePool = titlePoolFactory.createTitlePool(interpreterString);
        return titlePool;
    } else if (opString == "talk") {
        TalkEventPool* talkEventPool;
        TalkEventPoolFactory talkEventPoolFactory;
        talkEventPool = talkEventPoolFactory.createTalkEventPool(interpreterString, gameInformation.getPlayerType());
        return talkEventPool;
    }
    assert(0);
    return 0;
}
