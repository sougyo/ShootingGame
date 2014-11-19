#include "movePatternFactory.h"

using std::replace;
using std::count;
using std::string;
using std::istringstream;
using std::ostringstream;
using factory::MovePatternFactory;
using gameutil::MovePattern;

MovePatternFactory::MovePatternFactory(void) {
}

MovePatternFactory::~MovePatternFactory(void) {
}

MovePattern* MovePatternFactory::createMovePattern(string mpStr) {
	int line = static_cast<int>(count(mpStr.begin(), mpStr.end(), '\n'));
	mpStr = changeAimToValue(mpStr);
	mpStr = changeHomingToValue(mpStr);
	replace(mpStr.begin(), mpStr.end(), ',', ' ');
	
	assert(line*2 == count(mpStr.begin(), mpStr.end(), ' '));
	
	istringstream in(mpStr);
	MovePattern* movePattern = new MovePattern(line);
	for (int i = 0; i < line; i++) {
		double ar;
		double atheta;
		unsigned time;
		
		in >> ar >> atheta >> time;
		movePattern->add(ar, atheta, time);
	}

	return movePattern;
}

string& MovePatternFactory::changeAimToValue(string& original) {
	istringstream in(original);
	ostringstream out;
	while (in) {
		string temp;
		in >> temp;

		if (temp != "aim")
			out << temp << '\n';
		else
			out << 0 << ',' << MovePattern::Aim << ',' << 1 << '\n';
	}
	original = out.str();
	original.erase(original.size() - 1);

	return original;
}

string& MovePatternFactory::changeHomingToValue(string& original) {
	ostringstream out;
	out << MovePattern::Homing;
	
	int index;
	string homingStr = "homing";
	string valueStr = out.str();
	
	index = static_cast<int>(original.find(homingStr));
	while (index != static_cast<int>(original.npos)) {
		original.replace(index, homingStr.size(), valueStr);
		index = static_cast<int>(original.find(homingStr));
	}
	return original;
}
