#ifndef SIMPLE_MEASURE_H
#define SIMPLE_MEASURE_H
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <ctime>

template <typename T, typename U>
void outputResult(std::ofstream &output, U (T::*method)(), int n, int h)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	for (int i = 0; i <= n; i += h)
	{
		T object(i);

		std::clock_t start_time = std::clock();
		(object.*method)();
		double duration = 1000. * (std::clock() - start_time) / CLOCKS_PER_SEC;

		output << i << "," << duration << "\n";
		std::cout << "current : " << i << "\n";
	}
}

#endif
