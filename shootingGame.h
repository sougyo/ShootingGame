#ifndef ___SHOOTING_GAME_H
#define ___SHOOTING_GAME_H

#include <string>
#include "bomb.h"
#include "boss.h"
#include "bossPoolElement.h"
#include "bullet.h"
#include "constantField.h"
#include "continue.h"
#include "effectPool.h"
#include "effectFile.h"
#include "effectFileReader.h"
#include "enemy.h"
#include "effect.h"
#include "fighter.h"
#include "fighterFactory.h"
#include "fighterFileReader.h"
#include "gameInformation.h"
#include "interpreterFile.h"
#include "interpreterFileReader.h"
#include "item.h"
#include "itemKindMap.h"
#include "imageFactory.h"
#include "keyStore.h"
#include "keyStoreElement.h"
#include "label.h"
#include "labelFileReader.h"
#include "labelFactory.h"
#include "missile.h"
#include "missileSet.h"
#include "pause.h"
#include "poolScheduler.h"
#include "poolSchedulerFactory.h"
#include "stringDisplay.h"
#include "table.h"
#include "talkEvent.h"
#include "talkEventPoolElement.h"
#include "titlePoolElement.h"
#include "DirectSound.h"
#include "BackgroundController.h"

namespace gamesystem {
	class ShootingGame;
}

class gamesystem::ShootingGame {
private:
	static gamesystem::ShootingGame singleton;
	
private:
	gameutil::PoolScheduler* poolScheduler;
	gameutil::Table<bulletutil::Bullet> bulletTable;
	gameutil::Table<enemyutil::Enemy> enemyTable;
	gameutil::Table<itemutil::Item> itemTable;
	gameutil::Table<missileutil::Missile> missileTable;
	gameutil::Table<effectutil::Effect> effectTable;
	gameutil::Table<bossutil::Boss> bossTable;
	gameutil::Table<enemyutil::Enemy> bossEnemyTable;
	gameutil::Table<labelutil::Label> labelTable;
	gameutil::Table<bombutil::Bomb> bombTable;
	gameutil::Table<talkeventutil::TalkEvent> talkEventTable;
	gamesystem::Fighter* fighter;
	effectutil::EffectPool* enemyEffectPool;
	effectutil::EffectPool* bulletEffectPool;
	effectutil::EffectPool* fighterEffectPool;
	effectutil::EffectPool* fighterCollisionEffectPool;
	effectutil::EffectPool* clearEffectPool;
	gamesystem::GameInformation* gameInformation;
	gamesystem::KeyStore keyStore;
	gamesystem::Pause* pause;
	gamesystem::Continue* continue_;
	gamesoundutil::DirectSound* directSound;
	labelutil::Label* missLabel;
	background::BackgroundController* backGround;
	bool isActive_;
	
private:
	ShootingGame(const gamesystem::ShootingGame&);
	const gamesystem::ShootingGame& operator=(const gamesystem::ShootingGame&);
	ShootingGame(void);
	~ShootingGame(void);

private:
	graphics::Image* activeImage;
	graphics::Image* inactiveImage;
	graphics::Image* sideBlackImage;
	graphics::Image* updownBlackImage;
	
public:
	static gamesystem::ShootingGame* getInstance(void) { return &singleton; }
	
public:
	void initializeMain(void);
	void initialize(gamesystem::GameInformation* gameInformation);
	void clean(void);
	void moveOneFrame(void);
	void draw(void);
	void setKeyData(gamesystem::KeyStoreElement);
	inline bool isActive(void) const { return isActive_; }
	inline gamesystem::KeyStore getKeyStore(void) const { return keyStore; }
	
private:
	void move(void);
	void checkCollision(void);
	void initializeTable(void);
	void initializeImage(void);
	void initializeClass(void);
	void initializeEffect(void);
	void clearTable(void);
	gameutil::PoolScheduler* createPoolScheduler(std::string);
	gamesystem::Fighter* createFighter(std::string);
	labelutil::Label* createLabel(std::string);
};

#endif // ___SHOOTING_GAME_H