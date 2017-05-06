#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"

int main()
{
	const int total_iterations = 500;
	const int max_list_size = 250;
	std::ofstream insertionSortTime;
	std::ofstream rmergeSortTime;
	insertionSortTime.open("./Data and Plot/otherExperiment1_is_data.out");
	rmergeSortTime.open("./Data and Plot/otherExperiment1_rms_data.out");

	for (int list_size = 5; list_size <= max_list_size; list_size += 5) {
		for (int range = 5; range <= max_list_size; range += 5) {
			std::clock_t duration_is  = 0;
			std::clock_t duration_rms = 0;
			
			for (int times = 1; times <= total_iterations; ++times) {
				SinglyLList randList(list_size, range);

				{
					SinglyLList list = randList;
					auto start_time_is = std::clock();
					list.insertionSort();
					duration_is += std::clock() - start_time_is;
				}

				{
					SinglyLList list = randList;
					auto start_time_rms = std::clock();
					list.rmergeSort();
					duration_rms += std::clock() - start_time_rms;
				}
			}
			
			insertionSortTime << 1000. * duration_is
				/ total_iterations / CLOCKS_PER_SEC << " ";
			rmergeSortTime << 1000. * duration_rms
				/ total_iterations / CLOCKS_PER_SEC << " ";
		}
		insertionSortTime << std::endl;
		rmergeSortTime    << std::endl;

		std::cout << "current : " << list_size << std::endl;
	}

	insertionSortTime.close();
	rmergeSortTime.close();
	return 0;
}
