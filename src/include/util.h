#pragma once

namespace util {
	enum CARDINAL {
		NORTH = 0,
		EAST,
		SOUTH,
		WEST
	};

	inline int mod(int a, int b) {
		return (a % b + b) % b;
	};
}