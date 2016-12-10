#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUZZ_SIZE 256
#define INITIAL_HEAP_MAX_ELEMENT 129
typedef struct{
	int key;
} element;

element *heap;
int currentHeapSize = 0;
int currentMaxSize = INITIAL_HEAP_MAX_ELEMENT;


void push( const element item );
void heapResize();
void print();


int main()
{
	FILE *input = fopen( "in.txt", "r" );
	if( input == NULL )
	{
		perror( "in.txt" );
		exit( EXIT_FAILURE );
	}

	// insert all item
	heap = malloc( INITIAL_HEAP_MAX_ELEMENT * sizeof heap);
	char buffer[ BUZZ_SIZE ];
	while ( fgets( buffer, BUZZ_SIZE, input ) != NULL ) // read in item 
	{
 		char *token = strtok( buffer, "," );
		while ( token != NULL )
		{
			int value = strtol( token, NULL, 10);
			element item = { value };
			push( item );
			token = strtok ( NULL, "," );
		}      	
	}		

	print();

	
	free( heap );
	fclose( input );
	return 0;
}

void push( const element item )
{
	if ( currentHeapSize == currentMaxSize )
		heapResize();
	
	int i = ++currentHeapSize;
	while ( ( i != 1 ) && ( item.key > heap[i/2].key ) )
	{
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
}
	
void heapResize()
{
	// double the heap size
	element *tmp = realloc( heap, (currentHeapSize * 2 - 1) * sizeof heap );
	if ( tmp == NULL )
	{
		printf( "out of memory\n" );	
		free( heap );
		exit( EXIT_FAILURE );
	}
	heap = tmp;
}

void print()
{
	for ( int i = 1; i <= currentHeapSize; ++i )
	{
		static int nextLevel = 1, weight = 1;	
		printf( "%3d ", heap[i].key );

		if ( i == nextLevel )
		{
			nextLevel = nextLevel + weight * 2;
			weight *= 2;
			printf( "\n" );
		}
	}
	printf( "\n" );
}
