#include <iostream>
#include "SinglyLList.h"

int main()
{
	SinglyLList list(10);
	list.mergeSort();
	cout << list.isSorted();

	return 0;
}
