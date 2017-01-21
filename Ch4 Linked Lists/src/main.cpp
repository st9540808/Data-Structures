/**
 * main funciton
 * with Linked lists checkers
 */

#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "SinglyLinkedList.h"
using namespace std::chrono;
using namespace std;

void testSLL(); // SLL testing module
double getInsertionSortTime(int length, default_random_engine &generator);
bool SLL_sortingchecker(); // checked if the list is sorted

int main()
{
	testSLL();
	return 0;
}


void testSLL()
{
	ofstream outputFile;
	outputFile.open("output.out");
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	for (int i = 0; i <= 20000; i += 200)
	{
		double elapseTime = getInsertionSortTime(i, generator);
		outputFile << i << ',' << elapseTime << endl;
		cout << i << "\n";
	}
	outputFile.close();
}

double getInsertionSortTime(int length, default_random_engine &generator)
{
	std::uniform_int_distribution<int> gen(0, length*2);
	std::uniform_int_distribution<int> select(0, 1);
	
	SinglyLinkedList<int> list;
	for (int i = 0; i < length; ++i)
	{
		int integer = gen(generator);
		int selectInsert = select(generator);
		switch (selectInsert)// always select insertAtFront()
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
	
	std::clock_t start_time = std::clock();
	list.insertionSort();
	double duration = 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC;
	return duration;
}

// check if the list is sorted
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
