#include <iostream>
#include <fstream>

#include "./../SinglyLList.h"
#include "simple_measure.h"

int main()
{
	const int total_iterations = 500000;
	std::ofstream probability1;
	std::ofstream probability2;
	probability1.open("./Data and Plot/Experiment1_data_1.out");
	probability2.open("./Data and Plot/Experiment1_data_2.out");

	for (int list_size = 1; list_size <= 100; ++list_size) {
		int timesFaster1 = 0;
		int timesFaster2 = 0;
		
		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size);
			
			// to solve by insertion sort
			SinglyLList list1(randList);
				
			auto start_time_1 = std::chrono::high_resolution_clock::now();
			list1.insertionSort();
			auto end_time_1 = std::chrono::high_resolution_clock::now();
			auto duration1  = std::chrono::duration_cast // insertion sort CPU Time
				<std::chrono::nanoseconds>(end_time_1 - start_time_1).count();


			// to solve by merge sort (recursive)
			SinglyLList list2(randList);
			auto start_time_2 = std::chrono::high_resolution_clock::now();
			list2.rmergeSort();
			auto end_time_2 = std::chrono::high_resolution_clock::now();
			auto duration2  = std::chrono::duration_cast // merge sort CPU Time
				<std::chrono::nanoseconds>(end_time_2 - start_time_2).count();

			// to solbe by merge sort (iterative)
			SinglyLList list3(randList);
			auto start_time_3 = std::chrono::high_resolution_clock::now();
			list2.imergeSort();
			auto end_time_3 = std::chrono::high_resolution_clock::now();
			auto duration3  = std::chrono::duration_cast // iterative merge sort CPU Time
				<std::chrono::nanoseconds>(end_time_3 - start_time_3).count();
			

			if (static_cast<long>(duration1) < static_cast<long>(duration2)) {
				++timesFaster1;
			}
			if (static_cast<long>(duration1) < static_cast<long>(duration3)) {
				++timesFaster2;
			}
		}
		std::cout << "current : " << list_size << std::endl;

		probability1 << list_size << "," << static_cast<double>(timesFaster1)
			/ static_cast<double>(total_iterations) << std::endl;
		probability2 << list_size << "," << static_cast<double>(timesFaster2)
			/ static_cast<double>(total_iterations) << std::endl;
	}

	probability1.close();
	probability2.close();

	return 0;
}
