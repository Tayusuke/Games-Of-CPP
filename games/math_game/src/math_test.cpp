#include "math.h"
#include <random>

void generate_Random(int& a, int& b, int& ans) {
	random_device rd;

	std::uniform_int_distribution<int> dist(1, 10000);

	a = dist(rd);
	b = dist(rd);

	ans = a + b;
}
