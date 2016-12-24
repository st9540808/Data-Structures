/**
 *	DataSturctures
 *	hw5_2
 *	Ch5 TREES
 *	p.230 Max Heap Exercise 6
 *
 *	detele an arbitrary element in max heap
 *
 *	compile info : gcc hw5_2.c -o hw5_2 -Wall -std=c99
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUZZ_SIZE 256
#define INITIAL_HEAP_MAX_ELEMENT 129
typedef struct
{
	int key;
} element;

element *heap;
int heapSize = 0;
int length = INITIAL_HEAP_MAX_ELEMENT;


int getPosition(int priority);
void deleteElement(int pos, int replace);
void maxHeapify_smaller(int i);
void maxHeapify_larger(int i);

void push(const element item);
void heapResize();
void print();
void clearBf();


int main()
{
	FILE *input = fopen("in.txt", "r");
	if (input == NULL)
	{
		perror("in.txt");
		exit(EXIT_FAILURE);
	}

	// insert all item
	printf("Create Max Heap");
	heap = malloc(INITIAL_HEAP_MAX_ELEMENT * sizeof heap);
	char buffer[ BUZZ_SIZE ];
	while (fgets(buffer, BUZZ_SIZE, input) != NULL)     // read in item
	{
		char *token = strtok(buffer, ",");
		while (token != NULL)
		{
			int value = strtol(token, NULL, 10);
			element item = { value };
			push(item);
			token = strtok(NULL, ",");
		}
	}
	print();

	char response;
	while (1)
	{
		printf("Delete element ? (Y/N) : ");
		response = getchar();

		if (response == 'Y' || response == 'y')
		{
			int pos, delete;
			printf("Choice element : ");
			scanf("%d", &delete);

			clock_t start_clock = clock();

			pos = getPosition(delete);
			if (pos == 0)
			{
				clearBf();
				continue;
			}

			element item = heap[ heapSize-- ];
			deleteElement(pos, item.key);

			print();
			printf("Spend time : %.6f sec.\n", (clock() - start_clock) / (double) CLOCKS_PER_SEC);
		}
		else if (response == 'N' || response == 'n')
			break;

		// clear input buffer
		clearBf();
	}
	free(heap);
	fclose(input);
	return 0;
}

int getPosition(int priority)
{
	// locate 'priority'
	int pos, notFound = 1;
	for (pos = 1; pos <= heapSize; ++pos)
		if (priority == heap[pos].key)
		{
			notFound = 0;
			break;
		}
	if (notFound)
	{
		fprintf(stderr, "item not found\n");
		return 0;
	}
	return pos;
}

void deleteElement(int pos, int replace)
{
	// if the replace is smaller than current priority
	if (replace < heap[pos].key)
	{
		heap[pos].key = replace;
		maxHeapify_smaller(pos);
	}
	else if (replace > heap[pos].key)   // greater than
	{
		heap[pos].key = replace;
		maxHeapify_larger(pos);
	}
}

void maxHeapify_smaller(int i)
{
	int l = 2 * i,     //left child
	    r = 2 * i + 1, //right child
	    largest;
	if (l <= heapSize && heap[l].key > heap[i].key)
		largest = l;
	else
		largest = i;

	if (r <= heapSize && heap[r].key > heap[largest].key)
		largest = r;

	if (largest != i)
	{
		element tmp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = tmp;
		maxHeapify_smaller(largest);
	}
}

void maxHeapify_larger(int i)
{
	int parent = i / 2;
	if (parent >= 1 && heap[i].key > heap[parent].key)
	{
		element tmp = heap[i];
		heap[i] = heap[parent];
		heap[parent] = tmp;
		maxHeapify_larger(parent);
	}
}

void push(const element item)
{
	if (heapSize == length)
		heapResize();

	int i = ++heapSize;
	while ((i != 1) && (item.key > heap[i / 2].key))
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

void heapResize()
{
	// double the heap size
	element *tmp = realloc(heap, (heapSize * 2 - 1) * sizeof heap);
	if (tmp == NULL)
	{
		printf("out of memory\n");
		free(heap);
		exit(EXIT_FAILURE);
	}
	heap = tmp;
}

void print()
{
	printf("Max Heap : \n");
	int nextLevel = 1, weight = 1;
	for (int i = 1; i <= heapSize; ++i)
	{
		printf("%3d ", heap[i].key);

		if (i == nextLevel)
		{
			nextLevel = nextLevel + weight * 2;
			weight *= 2;
			printf("\n");
		}
	}
	printf("\n");
}

void clearBf()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}
