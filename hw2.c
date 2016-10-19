/**
 *	DataSturctures
 *	hw2
 *	Ch2 Aarray and Structures 
 *	p.102 #9 "random walk" problem
 *	
 *	compile option : gcc hw2.c -o test -std=c99
 *	command line argument : ./test n(2<n<=40) m(2<m<=20)
 */

#include <stdio.h>
#include <stdlib.h>

enum position {	UPPERLEFT_CORNER = 1, UPPERRIGHT_CORNER = 2, 
				LOWERLEFT_CORNER = 3, LOWERRIGHT_CORNER = 4,
				LEFT_WALL = 4, RIGHT_WALL = 5, UPPER_WALL = 6, LOWER_WALL = 7,
				MIDDLE = 8 }; 

void randomWalk(int, int);

enum position currentPosition(const int ibug, const int jbug, const int n, const int m);


int** initializeCount(int, int);
void print(int**, int, int); //print out (1)total number of legal moves (2)the final count array  
void freeCount(int**, int);


int main()
{	
	int n = 5, m = 5;

	randomWalk(n, m);
	return 0;
}

void randomWalk(int n, int m)
{
	int** count = initializeCount(n, m);
	int ibug = 2, jbug = 1;

	for(int i = 0; i < 50000; ++i)
	{
		

	}
	
	printf("%d\n", currentPosition(ibug, jbug, n, m));
	print(count, n, m);
	freeCount(count, n);
}

enum position currentPosition(const int ibug, const int jbug, const int n, const int m)
{
	if( (ibug < n-1 && ibug > 0) && (jbug < m-1 && jbug > 0) )
		return MIDDLE;	 
	
	if( ibug < n-1 && ibug > 0 )
	{	
		if( jbug == 0 )   return LEFT_WALL;
		if( jbug == m-1 ) return RIGHT_WALL;
	}
	if( jbug < m-1 && jbug > 0 )
	{
		if( ibug == 0 )   return UPPER_WALL;
		if( ibug == n-1 ) return LOWER_WALL;
	}

}




int** initializeCount(int n, int m)
{
	int **count;
	count = calloc(n, sizeof(int *)); //n rows
	for(int i = 0; i < n; ++i)
	{
		count[i] = calloc(m , sizeof(int)); //m columns
		if(count[i] == NULL){
			fprintf(stderr, "out of memory\n");
			exit(EXIT_FAILURE);
		}
	}	
	return count;
}

void print(int** count, int n, int m)
{
	//(2) print final count array
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			printf("%d ", count[i][j]);
		printf("\n");
	}
}

void freeCount(int** count, int n)
{
	for(int i = 0; i < n; ++i) 
		free(count[i]);  
	free(count); 
}
