#include "titlePoolElement.h"

using gameutil::PoolElement;
using labelutil::Label;
using titleutil::TitlePoolElement;

gameutil::Table<Label>* TitlePoolElement::labelTable = 0;

TitlePoolElement::TitlePoolElement(Label* label, int x, int y, int time)
		: PoolElement(time) {
	this->label = label;
	this->x = x;
	this->y = y;
}

TitlePoolElement::~TitlePoolElement(void) {
	delete label;
}

void TitlePoolElement::execute(void) {
	labelTable->add(label, x, y);
}

bool TitlePoolElement::isActive(void) {
	return label->isActive();
}
