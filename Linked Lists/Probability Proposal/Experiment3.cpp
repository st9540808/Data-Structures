#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"

int main()
{
	const int total_iterations = 25;
	const int total_points = 20;
	const int limit = 300000;
	const int step = limit / total_points;

	std::ofstream rmergesortTime;
	std::ofstream imergesortTime;
	std::ofstream nmergesortTime;
	std::ofstream timsortTime;
	rmergesortTime.open("./Data and Plot/Experiment3_rms.out");
	imergesortTime.open("./Data and Plot/Experiment3_ims.out");
	nmergesortTime.open("./Data and Plot/Experiment3_nms.out");
	timsortTime.open("./Data and Plot/Experiment3_ts.out");

	for (int list_size = 5000; list_size <= limit; list_size += step) {
		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size);
			
			{	// recursive mergesort CPU Time	
				SinglyLList list(randList);

				auto start_time = std::clock();
				list.rmergeSort();
				double duration = 1000. * (std::clock() - start_time) / CLOCKS_PER_SEC;
				
				rmergesortTime << duration << " ";
			}

			{	// iterative mergesort CPU Time			
				SinglyLList list(randList);

				auto start_time = std::clock();
				list.imergeSort();
				double duration = 1000. * (std::clock() - start_time) / CLOCKS_PER_SEC;
				
				imergesortTime << duration << " ";
			}

			{	// natural mergesort CPU Time			
				SinglyLList list(randList);
				
				auto start_time = std::clock();
				list.naturalmergeSort();
				double duration = 1000. * (std::clock() - start_time) / CLOCKS_PER_SEC;
				
				nmergesortTime << duration << " ";
			}
			
			{	// timsort CPU Time			
				SinglyLList list(randList);
				
				auto start_time = std::clock();
				list.timSort(9);
				double duration = 1000. * (std::clock() - start_time) / CLOCKS_PER_SEC;
				
				timsortTime << duration << " ";
			}

		}
		rmergesortTime << std::endl;
		imergesortTime << std::endl;
		nmergesortTime << std::endl;
		timsortTime    << std::endl;

		std::cout << "current : " << list_size << std::endl;
	}

	rmergesortTime.close();
	imergesortTime.close();
	nmergesortTime.close();
	timsortTime.close();
	return 0;	
}
