#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"
#include "simple_measure.h"

int main()
{
	const int total_iterations = 25000;
	std::ofstream rmergeSortTime;

	for (int list_size = 1; list_size <= 100; ++list_size) {
		int timesFaster = 0;
		
		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size);
			
			// to solve by insertion sort
			SinglyLList list1(randList);
				
			auto start_time_1 = std::chrono::high_resolution_clock::now();
			list1.insertionSort();
			auto end_time_1 = std::chrono::high_resolution_clock::now();
	
			// insertion sort CPU Time
			auto duration1 = std::chrono::duration_cast
				<std::chrono::nanoseconds>(end_time_1 - start_time_1).count();


			// to solve by merge sort (recursive)
			SinglyLList list2(randList);
			auto start_time_2 = std::chrono::high_resolution_clock::now();
			list2.rmergeSort();
			auto end_time_2 = std::chrono::high_resolution_clock::now();
		
			// merge sort CPU Time
			auto duration2 = std::chrono::duration_cast
				<std::chrono::nanoseconds>(end_time_2 - start_time_2).count();

			if (static_cast<long>(duration1) < static_cast<long>(duration2)) {
				++timesFaster;
			}
		}

		std::cout << static_cast<double>(timesFaster)
			/ static_cast<double>(total_iterations) << std::endl;
	}

	return 0;
}
