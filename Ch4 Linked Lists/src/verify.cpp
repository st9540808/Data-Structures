#include <iostream>
#include "SinglyLList.h"

int main()
{
	SinglyLList list(9);

	list.print();
	list.printPrem();
	std::cout << std::endl;

	list.naturalmergeSort();

	list.print();
	list.printPrem();

//	std::cout << sizeof(ListNode);
	return 0;
}
