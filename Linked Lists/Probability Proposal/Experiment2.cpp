#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"

int main()
{
	const int total_iterations = 2500;
	const int list_size = 10000;
	std::ofstream runTime;
	runTime.open("./Data and Plot/Experiment2_data.out");

	for (int run_size = 1; run_size <= 100; ++run_size) {
		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size);
			
			auto start_time = std::clock();
			randList.timSort(run_size);
			double duration = 1000. * (std::clock() - start_time) / CLOCKS_PER_SEC;

			runTime << duration << " ";
		}
		runTime << std::endl;

		std::cout << "current : " << run_size << std::endl;
	}

	runTime.close();
	return 0;
}
