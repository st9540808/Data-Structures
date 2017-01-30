#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "SLL.h"
using namespace std::chrono;
using namespace std;

int main()
{
	int n = 2000, h = 1;
	ofstream insertionSortTime, rmergeSortTime;
	insertionSortTime.open("insertionSortTime.out");
	rmergeSortTime.open("rmergeSortTime.out");

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	for (int i = 0; i <= n; i += h)
	{
		SLL list_1(i);

		std::clock_t start_time1 = std::clock();
		list_1.insertionSort();
		double duration_insertionSort = 1000. * (clock() - start_time1) / CLOCKS_PER_SEC;

		insertionSortTime << i << "," << duration_insertionSort << "\n";
		cout << "insertionsort : " << i << "\n";
	}

	for (int i = 0; i <= n; i += h)
	{
		SLL list_2(i);

		std::clock_t start_time2 = std::clock();
		list_2.mergeSort();
		double duration_rmergeSort = 1000. * (clock() - start_time2) / CLOCKS_PER_SEC;

		rmergeSortTime << i << "," << duration_rmergeSort << "\n";
		cout << "rmergesort : " << i << "\n";
	}

	insertionSortTime.close();
	rmergeSortTime.close();
	return 0;
}
