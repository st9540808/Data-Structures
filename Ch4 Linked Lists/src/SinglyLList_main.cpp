#include <fstream>
#include "SinglyLList.h"
#include "simple_measure.h"

int main()
{
	int points = 100;
	int n = 200000, h = n / points;
//	std::ofstream insertionSortTime;
	std::ofstream rmergeSortTime;
	std::ofstream imergeSortTime;

//	insertionSortTime.open("./plot/insertionSortTime.out");
	rmergeSortTime.open("./plot/rmergeSortTime.out");
	imergeSortTime.open("./plot/imergeSortTime.out");

//	outputResult(insertionSortTime, &SinglyLList::insertionSort, n, h);
	outputResult(rmergeSortTime, &SinglyLList::rmergeSort, n, h);
	outputResult(imergeSortTime, &SinglyLList::imergeSort, n, h);

//	insertionSortTime.close();
	rmergeSortTime.close();
	imergeSortTime.close();
	return 0;
}
