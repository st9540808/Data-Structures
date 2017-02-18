#include <iostream>
#include "Heap.h"

int main()
{
	MaxHeap myHeap;
	myHeap.print_binary();
	myHeap.insert(4);
	std::cout << std::endl;
	myHeap.print_binary();

	return 0;
}
