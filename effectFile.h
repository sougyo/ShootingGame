#ifndef ___EFFECT_FILE_H
#define ___EFFECT_FILE_H

#include <cassert>
#include <string>
#include <vector>

namespace effectIO {
	class EffectFile;
}

class effectIO::EffectFile {
private:
	std::vector<std::string> effectElements;
	
private:
	EffectFile(const effectIO::EffectFile&);
	const effectIO::EffectFile& operator=(const effectIO::EffectFile&);

public:
	EffectFile(void);
	~EffectFile(void);

public:
	void addEffectElement(std::string);
	std::string getEffectString(int);
	inline int getSize(void) const { return static_cast<int>(effectElements.size()); }
};

#endif // ___EFFECT_FILE_H