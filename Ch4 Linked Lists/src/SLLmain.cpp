#include "SLL.h"
#include "simple_measure.h"

int main()
{
	int n = 2000, h = 1;
	ofstream insertionSortTime, rmergeSortTime;
	insertionSortTime.open("./plot/insertionSortTime.out");
	rmergeSortTime.open("./plot/rmergeSortTime.out");

	outputResult(insertionSortTime, &SLL::insertionSort, n, h);
	outputResult(rmergeSortTime, &SLL::rmergeSort, n, h);

	insertionSortTime.close();
	rmergeSortTime.close();
	return 0;
}
