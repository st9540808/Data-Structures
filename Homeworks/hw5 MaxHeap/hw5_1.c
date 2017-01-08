/**
 *	DataSturctures
 *	hw5_1
 *	Ch5 TREES
 *	p.230 Max Heap Exercise 5
 *
 *	change priority of an arbitrary element in max heap
 *
 *	compile info : gcc hw5_1.c -o hw5_1 -Wall -std=c99
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
void changePriority(int pos, int newPriority);
void maxHeapify_smaller(int i);
void maxHeapify_larger(int i);

void push(const element item);
void heapResize();
void print();


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
		printf("Change priority ? (Y/N) : ");
		response = getchar();

		if (response == 'Y' || response == 'y')
		{
			int pos, priority, newPriority;

			printf("Choice priority : ");
			scanf("%d", &priority);

			clock_t start_clock = clock();
			pos = getPosition(priority);

			if (pos == 0)
			{
				char c;
				while ((c = getchar()) != '\n' && c != EOF);
				continue;
			}

			printf("change priority to : ");
			scanf("%d", &newPriority);
			changePriority(pos, newPriority);   // change priority function call

			print();
			printf("Spend time : %.6f sec.\n", (clock() - start_clock) / (double) CLOCKS_PER_SEC);
		}
		else if (response == 'N' || response == 'n')
			break;

		// clear input buffer
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
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

void changePriority(int pos, int newPriority)
{
	// if the newPriority is smaller than current priority
	if (newPriority < heap[pos].key)
	{
		heap[pos].key = newPriority;
		maxHeapify_smaller(pos);
	}
	else if (newPriority > heap[pos].key)   // greater than
	{
		heap[pos].key = newPriority;
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
