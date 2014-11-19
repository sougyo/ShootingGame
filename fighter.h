#ifndef ___FIGHTER_H
#define ___FIGHTER_H

#include <cmath>
#include "gamefwd.h"
#include "bomb.h"
#include "constantField.h"
#include "image.h"
#include "imageFactory.h"
#include "label.h"
#include "labelFactory.h"
#include "labelFileReader.h"
#include "missileSetController.h"
#include "table.h"

namespace gamesystem {
	const double SQRT2 = std::sqrt(2.0);
}

class gamesystem::Fighter {
public:
	static gameutil::Table<bombutil::Bomb>* bombTable;
	static gameutil::Table<labelutil::Label>* labelTable;
	
private:
	int radius;
	double speed;
	double slowSpeed;
	bool slowFlag;
	bool keyFlag;
	bool attacked_;
	int collisionCount;
	int invincibilityCount;
	double x;
	double y;
	double vx;
	double vy;
	bombutil::Bomb* bomb_;
	missileutil::MissileSetController* missileSetController;
	graphics::Image* circleImage;
	graphics::Image* image;
	labelutil::Label* cancelLabel;
	
	static const int COLLISIONCOUNTMAX = 20;
	
private:
	Fighter(const gamesystem::Fighter&);
	const gamesystem::Fighter& operator=(const gamesystem::Fighter&);
	
public:
	Fighter(int, double, double, graphics::Image*, missileutil::MissileSetController*);
	~Fighter(void);
	
public:
	void move(void);
	void draw(void);
	void initAttacked(void);
	void collision(void);
	inline int getRadius(void) const { return radius; }
	inline int getImageRadius(void) const { return image->getRadius(); }
	inline bool isAttacked(void) const { return attacked_; }
	inline bool isCollision(void) const { return collisionCount > 0; }
	inline bool isCollisionStart(void) const { return collisionCount == COLLISIONCOUNTMAX-1; }
	inline bool isInvincibility(void) const { return invincibilityCount > 0 || bomb_->isActive(); }
	inline int getX(void) const { return static_cast<int>(x); }
	inline int getY(void) const { return static_cast<int>(y); }
	
public:
	void up(void);
	void down(void);
	void left(void);
	void right(void);
	void slow(void);
	void shot(int);
	void bomb(void);
	
private:
	inline void toInvincibility(void) { invincibilityCount = 100; }
	void resetFlags(void);
	labelutil::Label* createCancelLabel(void);
};

#endif // ___FIGHTER_H