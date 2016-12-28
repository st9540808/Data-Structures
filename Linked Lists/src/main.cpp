/**
 * main funciton &
 * Linked lists checkers
 */

#include <iostream>
#include <random>
#include <chrono>
#include "Solution.h"

int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_int_distribution<int> gen(1, 10);
	unsigned listSize = gen(generator);

	Solution<int> list;

	return 0;
}
