#include "effectFactory.h"

using std::count;
using std::istringstream;
using std::string;
using effectutil::Effect;
using factory::EffectFactory;
using graphics::ImageFactory;

EffectFactory::EffectFactory(void) {
}

EffectFactory::~EffectFactory(void) {
}

Effect* EffectFactory::createEffect(string efStr) {
	ImageFactory* imageFactory = ImageFactory::getInstance();
	int size = static_cast<int>(count(efStr.begin(), efStr.end(), '\n'));
	istringstream in(efStr);
	Effect* effect = new Effect(size);
	char buf[1025];
	for (int i = 0; i < size; i++) {
		in.getline(buf, 1024);
		string fileName = gameutil::EFFECT_IMAGE_PATH + buf;
		effect->addEffectImage(imageFactory->createImage(fileName.c_str()));
	}
	return effect;
}
