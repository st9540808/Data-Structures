/**
 *	DataSturctures
 *	hw1_2
 *	Ch1 Basic Concept
 *	Powerset
 *
 *	compile info : gcc hw1_2.c -o test -std=c99
 */

#include <stdio.h>

void powerSet(char [], int);
void printCombination(char [], int, int);
void combination(char [], int, int, int, char [], int);

int main()
{
	char list[3] = {'a', 'b', 'c'};

	powerSet(list, 3);
	return 0;
}


void powerSet(char array[], int size)
{
	static int k = 0;

	if (k > size)
		return;
	else
	{
		printCombination(array, size, k);
		++k;
		powerSet(array, size);
	}
}

void printCombination(char array[], int size, int k)
{
	char data[size];

	combination(array, size, k, 0, data, 0);
}

void combination(char array[], int size, int k, int index, char data[], int i)
{
	if (index == k)
	{
		printf("{ ");
		for (int j = 0; j < k; ++j)
			printf("%c ", data[j]);
		printf("}\n");
		return;
	}
	if (i >= size)
		return;

	data[index] = array[i];
	combination(array, size, k, index + 1, data, i + 1);
	combination(array, size, k, index, data, i + 1);
}
