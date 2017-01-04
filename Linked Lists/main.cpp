/**
 * main funciton
 * with Linked lists checkers
 */

#include <iostream>
#include <random>
#include <chrono>
#include "SinglyLinkedList.h"
using namespace std;

int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_int_distribution<int> gen(1, 500);
	unsigned listSize = gen(generator);

	SinglyLinkedList<int> list;
	for (unsigned i = 0; i < listSize; ++i)
	{
		unsigned integer = gen(generator);
		switch (integer % 2)
		{
			case 0:
				list.insertAtEnd(integer);
				break;
			case 1:
				list.insertAtFront(integer);
				break;
			default:
				break;
		}
	}

	list.print();

	return 0;
}
