#ifndef ___GAME_MATH_H
#define ___GAME_MATH_H

namespace gamemath {
	const double PI = 3.14159265358979323846264338;
	
	inline double toRadian(double deg) {
		return deg * PI / 180.0;
	}

	inline double toDegree(double rad) {
		return rad * 180.0 / PI;
	}
}

#endif ___GAME_MATH_H