#include <iostream>
#include "SLL.h"

int main()
{
	SLL myList(100000);
	myList.mergeSort();
	std::cout << myList.isSorted();

	return 0;
}
