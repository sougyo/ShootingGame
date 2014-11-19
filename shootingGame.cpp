#include "shootingGame.h"

using std::string;
using namespace bossutil;
using namespace bombutil;
using namespace bulletutil;
using namespace effectutil;
using namespace effectIO;
using namespace enemyutil;
using namespace factory;
using namespace itemutil;
using namespace labelutil;
using namespace labelIO;
using namespace gamesystem;
using namespace gamesystemIO;
using namespace gameutil;
using namespace missileutil;
using namespace interpreterIO;
using namespace talkeventutil;
using namespace titleutil;
using gamesoundutil::DirectSound;

ShootingGame ShootingGame::singleton;

ShootingGame::ShootingGame(void) : bulletTable(1000), enemyTable(100), itemTable(100), missileTable(100), effectTable(1000), bossTable(10), bossEnemyTable(10), labelTable(20), bombTable(2), talkEventTable(1) {
}

ShootingGame::~ShootingGame(void) {
	delete bulletEffectPool;
	delete enemyEffectPool;
	delete clearEffectPool;
	delete fighterCollisionEffectPool;
	delete fighterEffectPool;
}

void ShootingGame::initializeMain(void) {
	initializeEffect();
	ItemKindMap::getInstance()->initialize();
	StringDisplay::getInstance()->initialize();
	directSound = DirectSound::getInstance();
	backGround = background::BackgroundController::getInstance();
}

void ShootingGame::initialize(GameInformation* gameInformation) {
	directSound->stop();

	isActive_ = true;
	this->gameInformation = gameInformation;
	this->fighter = createFighter(gameInformation->getFighterName());
	this->pause = new Pause(gameInformation);
	this->continue_ = new Continue;
	this->missLabel = createLabel("miss.lbl");
	keyStore = KeyStore();

	initializeClass();
	initializeTable();
	initializeImage();
	
	poolScheduler = createPoolScheduler(gameInformation->getStageFileName());
	poolScheduler->start();

	backGround->load(gameInformation->getStageNo());
	directSound->setTrack(gameInformation->getStageNo());
	directSound->play();
}

void ShootingGame::clean(void) {
	clearTable();
	delete fighter;
	delete poolScheduler;
	delete pause;
	delete continue_;
	delete missLabel;
	fighterCollisionEffectPool->clean();
	fighterEffectPool->clean();
	enemyEffectPool->clean();
	bulletEffectPool->clean();
	clearEffectPool->clean();
	backGround->claen();
}

void ShootingGame::moveOneFrame(void) {
	if (continue_->isContinue()) {
		delete continue_;
		continue_ = new Continue;
		gameInformation->continueInitialize();
	}
	if (continue_->isNotContinue()) {
		isActive_ = false;
		return;
	}
	
	if (continue_->isActive()) {
		if (!directSound->isPausing())
			directSound->pause();
		continue_->move();
		bulletTable.clear();
		enemyTable.clear();
		effectTable.move();
		labelTable.move();
	} else if (pause->isActive()) {
		if (!directSound->isPausing())
			directSound->pause();
		pause->move();
	} else {
		if (directSound->isPausing())
			directSound->play();
		move();
		checkCollision();
	}
}

void ShootingGame::setKeyData(KeyStoreElement keyStoreElement) {
	this->pause->setKeyData(keyStoreElement);
	this->continue_->setKeyData(keyStoreElement);

	if (talkEventTable.getSize() != 0)
		talkEventTable.getArray()[0]->setKeyData(keyStoreElement);;

	if (!this->pause->isActive() && !this->continue_->isActive()) {
		bool up		= keyStoreElement.isUp();
		bool down	= keyStoreElement.isDown();
		bool left	= keyStoreElement.isLeft();
		bool right	= keyStoreElement.isRight();
		bool shot	= keyStoreElement.isShot();
		bool bomb	= keyStoreElement.isBomb();
		bool slow	= keyStoreElement.isSlow();
		bool skip	= keyStoreElement.isSkip();
		bool pause	= keyStoreElement.isPause();
		keyStore.addKeyStoreElement(up, down, left, right, shot, bomb, slow, skip, pause);
		if (up)
			fighter->up();
		if (down)
			fighter->down();
		if (left)
			fighter->left();
		if (right)
			fighter->right();
		if (slow)
			fighter->slow();
		if (talkEventTable.getSize() == 0) {
			if (bomb)
				fighter->bomb();
			if (shot)
				fighter->shot(gameInformation->getPower());
		}
	}
}

void ShootingGame::move(void) {
	effectTable.move();
	bulletTable.move();
	enemyTable.move();
	bossEnemyTable.move();
	itemTable.move();
	fighter->move();
	bossTable.move();
	missileTable.move();
	labelTable.move();
	bombTable.move();
	poolScheduler->move();
	talkEventTable.move();
	backGround->move();
	if (fighter->isCollisionStart())
		fighterCollisionEffectPool->fire(fighter->getX(), fighter->getY());
	if (fighter->isAttacked()) {
		fighter->initAttacked();
		fighterEffectPool->fire(fighter->getX(), fighter->getY());
		gameInformation->subtractPlayer();
		labelTable.add(missLabel, fighter->getX(), fighter->getY());
	}
	if (!poolScheduler->isActive()) {
		if (gameInformation->isLastStage())
			gameInformation->setState(endstate::GAMECLEARSTATE);
		else
			gameInformation->setState(endstate::STAGECLEARSTATE);
	}
	if (!gameInformation->isGamePlaying()) {
		if (gameInformation->isStoryMode() && gameInformation->getState() == endstate::GAMEOVERSTATE)
			continue_->show();
		else
			isActive_ = false;
	}
}

void ShootingGame::draw(void) {
	if (continue_->isActive()) {
		continue_->draw();
		return;
	}
	if (!isActive_ || !gameInformation->isGamePlaying()) {
		gameutil::drawNowLoadingImage();
		return;
	}
	//if (keyStore.getSize() != 0 && !keyStore.getKeyStoreElement(keyStore.getSize()-1).isSkip())
        backGround->draw();
	if (!pause->isActive()) {
		effectTable.draw();
		missileTable.draw();
		bombTable.draw();
		itemTable.draw();
		bossEnemyTable.draw();
	}
	fighter->draw();
	enemyTable.draw();
	if (!pause->isActive()) {
		bossTable.draw();
		bulletTable.draw();
		labelTable.draw();
		talkEventTable.draw();
	}
	updownBlackImage->drawImage(0, 350, -50);
	updownBlackImage->drawImage(0, 350, gameutil::HEIGHT + 50);
	sideBlackImage->drawImage(0, -150, 240);
	sideBlackImage->drawImage(0, gameutil::WIDTH + 150, 240);
	gameInformation->draw();
	pause->draw();
}

void ShootingGame::checkCollision(void) {
	Bullet** bullets = bulletTable.getArray();
	Missile** missiles = missileTable.getArray();
	Enemy** enemys = enemyTable.getArray();
	Enemy** bossEnemys = bossEnemyTable.getArray();
	Item** items = itemTable.getArray();
	Bomb** bombs = bombTable.getArray();
	for (int i = 0; i < enemyTable.getSize(); i++) {
		if (enemys[i] == 0)
			continue;
		for (int j = 0; j < missileTable.getSize(); j++) {
			if (missiles[j] == 0)
				continue;
			enemys[i]->checkCollision(missiles[j]);
		}
		for (int j = 0; j < bombTable.getSize(); j++) {
			if (bombs[j] == 0)
				continue;
			enemys[i]->checkCollision(bombs[j]);
		}
		enemys[i]->checkCollision(fighter);
	}
	for (int i = 0; i < bossEnemyTable.getSize(); i++) {
		if (bossEnemys[i] == 0)
			continue;
		for (int j = 0; j < missileTable.getSize(); j++) {
			if (missiles[j] == 0)
				continue;
			bossEnemys[i]->checkCollision(missiles[j]);
		}
		for (int j = 0; j < bombTable.getSize(); j++) {
			if (bombs[j] == 0)
				continue;
			bossEnemys[i]->checkCollision(bombs[j]);
		}
		bossEnemys[i]->checkCollision(fighter);
	}
	for (int i = 0; i < bulletTable.getSize(); i++) {
		if (bullets[i] == 0)
			continue;
		bullets[i]->checkCollision(fighter);
		for (int j = 0; j < bombTable.getSize(); j++) {
			if (bombs[j] == 0)
				continue;
			bullets[i]->checkCollision(bombs[j]);
		}
		gameInformation->addScore(bullets[i]->getSize());
	}
	for (int i = 0; i < itemTable.getSize(); i++) {
		if (items[i] == 0)
			continue;
		items[i]->checkCollision(fighter);
	}

/*
	Boss** bosses = bossTable.getArray();
	Effect** effects = effectTable->getArray();
	for (int i = 0; i < bulletTable->getSize(); i++) {
		if (bullets[i] != 0)
			activeImage->drawImage(0, i*10, 10);
		else
			inactiveImage->drawImage(0, i*10, 10);
	}
	for (int i = 0; i < enemyTable->getSize(); i++) {
		if (enemys[i] != 0)
			activeImage->drawImage(0, i*10, 22);
		else
			inactiveImage->drawImage(0, i*10, 22);
	}
	for (int i = 0; i < missileTable->getSize(); i++) {
		if (missiles[i] != 0)
			activeImage->drawImage(0, i*10, 33);
		else
			inactiveImage->drawImage(0, i*10, 33);
	}
	for (int i = 0; i < itemTable->getSize(); i++) {
		if (items[i] != 0)
			activeImage->drawImage(0, i*10, 44);
		else
			inactiveImage->drawImage(0, i*10, 44);
	}
	for (int i = 0; i < effectTable->getSize(); i++) {
		if (effects[i] != 0)
			activeImage->drawImage(0, i*10, 55);
		else
			inactiveImage->drawImage(0, i*10, 55);
	}
	for (int i = 0; i < bossEnemyTable.getSize(); i++) {
		if (bossEnemys[i] != 0)
			activeImage->drawImage(0, i*10, 66);
		else
			inactiveImage->drawImage(0, i*10, 66);
	}
	for (int i = 0; i < bossTable.getSize(); i++) {
		if (bosses[i] != 0)
			activeImage->drawImage(0, i*10, 77);
		else
			inactiveImage->drawImage(0, i*10, 77);
	}*/
}

void ShootingGame::initializeTable(void) {
	Enemy::bulletTable = &this->bulletTable;
	Enemy::enemyTable = &this->enemyTable;
	Enemy::itemTable = &this->itemTable;
	MissileSet::missileTable = &this->missileTable;
	EffectPool::effectTable = &this->effectTable;
	EnemyPoolElement::enemyTable =&this->enemyTable;
	MovePattern::enemyTable = &this->enemyTable;
	BossElement::enemyTable = &this->bossEnemyTable;
	BossPoolElement::bossTable = &this->bossTable;
	Boss::bulletTable = &this->bulletTable;
	Boss::enemyTable = &this->enemyTable;
	TitlePoolElement::labelTable = &this->labelTable;
	Fighter::bombTable = &this->bombTable;
	Fighter::labelTable = &this->labelTable;
	TalkEventPoolElement::talkEventTable = &this->talkEventTable;
	TalkEventPoolElement::enemyTable = &this->enemyTable;
	TalkEventPoolElement::bulletTable = &this->bulletTable;
	MovePattern::enemyTable = &this->enemyTable;
	MovePattern::bossEnemyTable = &this->bossEnemyTable;
}

void ShootingGame::initializeImage(void) {
	activeImage = graphics::ImageFactory::getInstance()->createImage("images/active.png");
	inactiveImage = graphics::ImageFactory::getInstance()->createImage("images/inactive.png");
	updownBlackImage = graphics::ImageFactory::getInstance()->createImage("images/black(800,100).bmp");
	sideBlackImage = graphics::ImageFactory::getInstance()->createImage("images/black(300,480).bmp");
}

void ShootingGame::initializeClass(void) {
	EnemyElement::effectPool = this->enemyEffectPool;
	BulletElement::effectPool = this->bulletEffectPool;
	TalkEventPoolElement::clearEffectPool = this->clearEffectPool;
	EnemyElement::gameInformation = this->gameInformation;
	MovePattern::fighter = this->fighter;
	MissileElement::fighter = this->fighter;
	ItemKind::gameInformation = this->gameInformation;
	BulletElement::gameInformation = this->gameInformation;
	Bomb::gameInformation = this->gameInformation;
	BossElement::gameInformation = this->gameInformation;
}

void ShootingGame::initializeEffect(void) {
	EffectFileReader efr(gameutil::DATA_PATH.c_str(), gameutil::EFFECTFILE_PATH.c_str());
	EffectFile* effectFile = efr.createEffectFile();
	enemyEffectPool		= new EffectPool(50, effectFile->getEffectString(gameutil::ENEMYEFFECT_INDEX));
	bulletEffectPool	= new EffectPool(700, effectFile->getEffectString(gameutil::BULLETEFFECT_INDEX));
	fighterEffectPool	= new EffectPool(1, effectFile->getEffectString(gameutil::FIGHTEREFFECT_INDEX));
	fighterCollisionEffectPool = new EffectPool(1, effectFile->getEffectString(gameutil::FIGHTERCOLLISIONEFFECT_INDEX));
	clearEffectPool		= new EffectPool(200, effectFile->getEffectString(gameutil::CLEAREFFECT_INDEX));
	delete effectFile;
}

void ShootingGame::clearTable(void) {
	bulletTable.clear();
	enemyTable.clear();
	itemTable.clear();
	missileTable.clear();
	effectTable.clear();
	bossTable.clear();
	bossEnemyTable.clear();
	labelTable.clear();	
	talkEventTable.clear();
	bombTable.clear();
}

PoolScheduler* ShootingGame::createPoolScheduler(string fileName) {
	InterpreterFileReader interpreterFileReader(gameutil::DATA_PATH.c_str(), fileName.c_str());
	InterpreterFile* interpreterFile = interpreterFileReader.createInterpreterFile();
	
	PoolSchedulerFactory poolSchedulerFactory;
	PoolScheduler* poolScheduler = poolSchedulerFactory.createPoolScheduler(*interpreterFile, *gameInformation);
	
	delete interpreterFile;
	
	return poolScheduler;
}

Fighter* ShootingGame::createFighter(string fighterName) {
	FighterFileReader fighterFileReader(fighterName);
	FighterFile* fighterFile = fighterFileReader.createFighterFile();
	FighterFactory fighterFactory;
	fighter = fighterFactory.createFighter(*fighterFile);
	delete fighterFile;
	return fighter;
}

Label* ShootingGame::createLabel(string fileName) {
	LabelFileReader labelFileReader(gameutil::DATA_PATH.c_str(), fileName.c_str());
	LabelFile* labelFile = labelFileReader.createLabelFile();
	LabelFactory labelFactory;
	Label* label = labelFactory.createLabel(*labelFile);
	delete labelFile;
	return label;
}