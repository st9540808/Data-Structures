#include <iostream>
#include "SinglyLList.h"

int main()
{
	SinglyLList list(10);
	list.imergeSort();
	std::cout << list.isSorted() << std::endl;
	std::cout << sizeof(ListNode) << std::endl;

	return 0;
}
