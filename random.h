#ifndef ___RANDOM_H
#define ___RANDOM_H

namespace gameutil {
	class Random;
}

class gameutil::Random {
private:
	unsigned char seed;
	
public:
	Random(unsigned char seed) : seed(seed) {}
	~Random(void) {}
	unsigned char rand() {
		return seed = seed * 94256721 + 1;
	}
};

#endif // ___RANDOM_H