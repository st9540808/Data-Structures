#include <iostream>
#include "SLL.h"

int main()
{
	SLL list(1000000);
	list.mergeSort();
	cout << list.isSorted();

	return 0;
}
