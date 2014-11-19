#ifndef ___CONSTANT_FIELD_H
#define ___CONSTANT_FIELD_H

#include <string>

namespace gameutil {
	const int HEIGHT = 450;
	const int WIDTH = 400;
	
	const int BLANK = 100;
	
	const int LEFT = -BLANK;
	const int RIGHT = WIDTH + BLANK;
	const int TOP = -BLANK;
	const int BOTTOM = HEIGHT + BLANK;
	
	const std::string IMAGE_PATH("images/");
	const std::string ITEM_IMAGE_PATH	= IMAGE_PATH + "item/";
	const std::string EFFECT_IMAGE_PATH	= IMAGE_PATH + "effect/";
	const std::string NUMBER_IMAGE_PATH	= IMAGE_PATH + "number/";
	const std::string ALPHA_IMAGE_PATH	= IMAGE_PATH + "alpha/";
	const std::string GAUGE_IMAGE_PATH	= IMAGE_PATH + "gauge/";
	const std::string LABEL_IMAGE_PATH	= IMAGE_PATH + "label/";
	const std::string STATE_IMAGE_PATH	= IMAGE_PATH + "state/";
	const std::string DATA_PATH("files.dat");
	const std::string FIGHTERFILE_PATH("fighter.ftr");
	const std::string EFFECTFILE_PATH("effect.eft");
	const std::string ENDINGFILE_PATH("ending.itp");
	const std::string REPLAYFILE_PATH("replay/");
	const std::string SCOREFILE_PATH("score.dat");
	
	const int BIG_POWER = 8;
	const int BOMB_INITIALVALUE = 3;
	const int BOMB_MAX = 9;
	const int POWER_MAX = 100;
	const int PLAYER_MAX = 9;
	
	const int ENEMYEFFECT_INDEX = 0;
	const int BULLETEFFECT_INDEX = 1;
	const int FIGHTEREFFECT_INDEX = 2;
	const int FIGHTERCOLLISIONEFFECT_INDEX = 3;
	const int CLEAREFFECT_INDEX = 4;
	
	const int LASTSTAGE = 6;
	const int SAVERANKSIZE = 8;
}

#endif // ___CONSTANT_FIELD_H