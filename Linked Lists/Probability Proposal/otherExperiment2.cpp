#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"

int main()
{
	const int total_iterations = 300;
	const int max_list_size = 1000;

	std::ofstream insertionSortTime;
	std::ofstream rmergeSortTime;
	std::ofstream imergeSortTime;
	insertionSortTime.open("./Data and Plot/otherExperiment2_is_data.out");
	rmergeSortTime.open("./Data and Plot/otherExperiment2_rms_data.out");
	imergeSortTime.open("./Data and Plot/otherExperiment2_ims_data.out");

	for (int list_size = 0; list_size <= max_list_size; list_size += 50) {
		std::clock_t duration_is  = 0;
		std::clock_t duration_rms = 0;
		std::clock_t duration_ims = 0;

		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size);

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.insertionSort();
				duration_is += std::clock() - start_time;
			}

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.rmergeSort();
				duration_rms += std::clock() - start_time;
			}

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.rmergeSort();
				duration_ims += std::clock() - start_time;
			}
		}
			
		insertionSortTime << list_size << "," << 1000. * duration_is
			/ total_iterations / CLOCKS_PER_SEC;
		rmergeSortTime    << list_size << "," << 1000. * duration_rms
			/ total_iterations / CLOCKS_PER_SEC;
		imergeSortTime    << list_size << "," << 1000. * duration_ims
			/ total_iterations / CLOCKS_PER_SEC;

		insertionSortTime << std::endl;
		rmergeSortTime    << std::endl;
		imergeSortTime    << std::endl;

		std::cout << "current : " << list_size << std::endl;
	}

	insertionSortTime.close();
	rmergeSortTime.close();
	imergeSortTime.close();
	return 0;
}
