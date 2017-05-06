#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"

int main()
{
	const int total_iterations = 35;
	std::ofstream runTime;
	runTime.open("./Data and Plot/Experiment2_2data.out");

	for (int list_size = 1000; list_size <= 25000; list_size += 500) {
		for (int run_size = 1; run_size <= 99; run_size += 2) {
			std::clock_t duration = 0;
			
			for (int times = 1; times <= total_iterations; ++times) {
				SinglyLList randList(list_size);
			
				auto start_time = std::clock();
				randList.timSort(run_size);
				duration += std::clock() - start_time;
			}
			
			runTime << 1000. * duration
				/ total_iterations / CLOCKS_PER_SEC << " ";
		}
		
		runTime << "\n";
		std::cout << "current : " << list_size << std::endl;
	}

	runTime.close();
	return 0;
}
