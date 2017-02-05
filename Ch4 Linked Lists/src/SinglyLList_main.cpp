#include <fstream>
#include "SinglyLList.h"
#include "simple_measure.h"

int main()
{
	int n = 2000, h = 1;
	std::ofstream insertionSortTime, rmergeSortTime;
	insertionSortTime.open("./plot/insertionSortTime.out");
	rmergeSortTime.open("./plot/rmergeSortTime.out");

	outputResult(insertionSortTime, &SinglyLList::insertionSort, n, h);
	outputResult(rmergeSortTime, &SinglyLList::rmergeSort, n, h);

	insertionSortTime.close();
	rmergeSortTime.close();
	return 0;
}
