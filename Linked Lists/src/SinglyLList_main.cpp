#include <fstream>
#include "SinglyLList.h"
#include "simple_measure.h"

void test_timSort_with_different_runSize();
void test_iterative_mergeSort_and_variation(int n, int h);
void test_recursive_mergeSort_and_insertionSort(int n, int h);

int main()
{
	int points = 50;
	int n = 1000000, h = n / points;
	test_iterative_mergeSort_and_variation(n, h);

	return 0;
}


void test_iterative_mergeSort_and_variation(int n, int h)
{
	std::ofstream rmergeSortTime;
	std::ofstream imergeSortTime;
	std::ofstream naturalmergeSortTime;
	std::ofstream timSortTime;

	{
		SinglyLList list(100000);
		list.timSort();
	}

	rmergeSortTime.open("./plot/rmergeSortTime.out");
	imergeSortTime.open("./plot/imergeSortTime.out");
	naturalmergeSortTime.open("./plot/naturalmergeSortTime.out");
	timSortTime.open("./plot/timSortTime.out");
	
	outputResult(rmergeSortTime, &SinglyLList::rmergeSort, n, h);
	outputResult(imergeSortTime, &SinglyLList::imergeSort, n, h);
	outputResult(naturalmergeSortTime, &SinglyLList::naturalmergeSort, n, h);
	outputResult(timSortTime, &SinglyLList::timSort, n, h);

	rmergeSortTime.close();
	imergeSortTime.close();
	naturalmergeSortTime.close();
	timSortTime.close();
}

void test_recursive_mergeSort_and_insertionSort(int n, int h)
{
	std::ofstream insertionSortTime;
	std::ofstream rmergeSortTime;

	insertionSortTime.open("./plot/insertionSortTime.out");
	rmergeSortTime.open("./plot/rmergeSortTime.out");

	outputResult(insertionSortTime, &SinglyLList::insertionSort, n, h);
	outputResult(rmergeSortTime, &SinglyLList::rmergeSort, n, h);

	insertionSortTime.close();
	rmergeSortTime.close();
}
