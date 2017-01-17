/**
 * main funciton
 * with Linked lists checkers
 */

#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include "SinglyLinkedList.h"
using namespace std::chrono;
using namespace std;

void testSLL();
uint64_t getInsertionSortTime(int length,
		default_random_engine &generator); // change return type to unsigned
bool SLL_sortingchecker();

int main()
{
//	testSLL();
	for (int i = 0; i < 500; ++i)
		if (SLL_sortingchecker() == false)
			cout << "wrong\n";

	return 0;
}


void testSLL()
{
	ofstream outputFile;
	outputFile.open("output.out");
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	for (int i = 0; i <= 7500; i += 50)
	{
		uint64_t elapseTime = getInsertionSortTime(i, generator);
		outputFile << i << ',' << elapseTime << endl;
		cout << i << "\n";
	}
	outputFile.close();
}

uint64_t getInsertionSortTime(int length,
		default_random_engine &generator)
{
	std::uniform_int_distribution<int> gen(0, length*2);
	std::uniform_int_distribution<int> select(0, 1);
	
	SinglyLinkedList<int> list;
	for (int i = 0; i < length; ++i)
	{
		int integer = gen(generator);
//		int selectInsert = select(generator);
		switch (1)//selectInsert)
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
	cout << list.getSize() << " ";	
	list.print();
	cout << "\n";
	
	std::chrono::high_resolution_clock::time_point t1 = high_resolution_clock::now();
	list.insertionSort();
	std::chrono::high_resolution_clock::time_point t2 = high_resolution_clock::now();
	uint64_t duration = duration_cast<nanoseconds>(t2 - t1).count();
	list.print();
//	cout << duration << "\n";
	return duration;
}

bool SLL_sortingchecker()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> gen(0, 10000);
	
	SinglyLinkedList<int> list;
	int size = gen(generator);
	for (int i = 0; i < size; ++i)
		list.insertAtFront(gen(generator));
	list.insertionSort();
	list.print();

	return list.isSorted(); 
}