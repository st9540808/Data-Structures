#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#define PARENT(I) I >> 1
#define LEFT(I)   I << 1
#define RIGHT(I) (I << 1) + 1

class MaxHeap
{
public:
	MaxHeap() : heap{0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1} {} // first element is reserved
	MaxHeap(int size) : heap(size + 1, 0) {}
	inline auto heapSize() const
	{
		return heap.size() - 1;
	}

	void print() const
	{
		for (auto iter = heap.cbegin() + 1; iter !=	heap.cend(); ++iter)
			std::cout << *iter << " ";
		std::cout << "\n";
	}

	void print_binary() const
	{
		int nextLevel = 1, weight = 1;
		for (int i = 1; i <= heapSize(); ++i)
		{
			std::cout << std::setw(3) << heap[i] << " ";
	
			if (i == nextLevel)
			{
				nextLevel = nextLevel + weight * 2;
				weight *= 2;
				std::cout << "\n";
			}
		}
		std::cout << "\n";
	}

	void insert(const int &value)
	{
		maxHeapify(2);
	}

private:
	std::vector<int> heap;
	void maxHeapify(const int &i)
	{
		int left = LEFT(i), right = RIGHT(i);
		int largest = i;
		if (left <= heapSize() and heap[left] > heap[i])
			largest = left;
		if (right <= heapSize() and heap[right] > heap[largest])
			largest = right;
		if (largest != i)
		{
			std::iter_swap(heap.begin() + i, heap.begin() + largest);
			maxHeapify(largest);
		}	
	}
};

#endif
