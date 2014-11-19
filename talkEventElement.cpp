#include "talkEventElement.h"

using std::string;
using talkeventutil::TalkEventElement;

TalkEventElement::TalkEventElement(string message, int position) {
	this->message = message;
	this->position = position;
	std::replace(this->message.begin(), this->message.end(), ';', '\n');
}

TalkEventElement::~TalkEventElement(void) {
}

