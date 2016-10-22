/**
 *	DataSturctures
 *	hw2_2
 *	Ch2 Aarray and Structures 
 *	p.102 #9 "random walk" problem
 *	
 *	compile option : gcc hw2.c -o test -std=c99
 *	command line argument : ./test n(2<n<=40) m(2<m<=20) initialRow initialColumn
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE  1
#define FALSE 0


enum position {	UPPERLEFT_CORNER = 1, UPPERRIGHT_CORNER = 2, 
				LOWERLEFT_CORNER = 3, LOWERRIGHT_CORNER = 4,
				LEFT_WALL = 5, RIGHT_WALL = 6, UPPER_WALL = 7, LOWER_WALL = 8,
				MIDDLE = 9 }; 


void randomWalk				 (int, int, int, int);
int  randomSelectNextMove	 (const int, const int, const int, const int);
enum position currentPosition(const int, const int, const int, const int);
int	 allTileTouched			 (int **, const int, const int);


int** initializeCount(int, int);
void print(int**, int, int, int); //print out (1)total number of legal moves (2)the final count array  
void freeCount(int**, int);


int main(int argc, char *argv[])
{	
	if( argc != 5 )
	{
		fprintf(stderr, "input argument : n(2<n<=40) m(2<m<=20) initialRow initialColumn\n");
		exit(EXIT_FAILURE);
	}
	
	int inputArgument[4];
	for(int i = 0; i < 4; ++i)
		inputArgument[i] = strtol(argv[i+1], NULL, 10);		
	
	if( inputArgument[0] <= 2 || inputArgument[0] > 40 )
	{
		fprintf(stderr, "invalid n (Row Size)");
		exit(EXIT_FAILURE);
	}
	if( inputArgument[1] <= 2 || inputArgument[1] > 20 )
	{
		fprintf(stderr, "invalid m (Column Size)");
		exit(EXIT_FAILURE);
	}
	if( inputArgument[2] < 0 || inputArgument[2] > inputArgument[0])
	{
		fprintf(stderr, "invalid Initial Row Position");
		exit(EXIT_FAILURE);
	}
	if( inputArgument[3] < 0 || inputArgument[3] > inputArgument[1] )
	{
		fprintf(stderr, "invalid Initial Column Position");
		exit(EXIT_FAILURE);
	}

	
	srand((unsigned)time(NULL));
	randomWalk(inputArgument[0], inputArgument[1], inputArgument[2], inputArgument[3]);
	
	return 0;
}

void randomWalk(int n, int m, int ibug, int jbug)
{
	const int imove[8] = {-1, 0, 1, 1, 1, 0, -1, -1},
			  jmove[8] = {1 ,1 ,1 ,0 ,-1 ,-1 ,-1 ,0};
	int** count = initializeCount(n, m);
	int totalMoves = 0, nextMove = 0;
	
	count[ibug][jbug]++;
	do
	{
		nextMove = randomSelectNextMove(ibug, jbug, n, m);

		ibug = ibug + imove[nextMove];
		jbug = jbug + jmove[nextMove];

		++count[ibug][jbug];
		++totalMoves;
	}while( allTileTouched(count, n, m) != TRUE );
	
	print(count, n, m, totalMoves);
	freeCount(count, n);
}


int randomSelectNextMove(const int ibug, const int jbug, const int n, const int m)
{
	static const int nextMove[12] = {0,1,2,3,4,5,6,7,0,1,2,3};
	switch( currentPosition(ibug, jbug, n, m) )
	{
		case MIDDLE	: return nextMove[rand() % 8];

		case LEFT_WALL : return nextMove[rand() % 5 + 7];
		case RIGHT_WALL : return nextMove[rand() % 5 + 3];
		case UPPER_WALL : return nextMove[rand() % 5 + 1];
		case LOWER_WALL : return nextMove[rand() % 5 + 5];
						  
		case UPPERLEFT_CORNER : return nextMove[rand() % 3 + 1];
		case LOWERLEFT_CORNER :	return nextMove[rand() % 3 + 7];
		case UPPERRIGHT_CORNER : return nextMove[rand() % 3 + 3];
		case LOWERRIGHT_CORNER : return nextMove[rand() % 3 + 5];
		
		default : fprintf(stderr, "illegal position\n");
					   exit(EXIT_FAILURE);
	}
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

	if( ibug == 0 )
	{
		if( jbug == 0 )   return UPPERLEFT_CORNER;
		if( jbug == m-1 ) return UPPERRIGHT_CORNER;
	}
	if( ibug == n-1 )
	{
		if( jbug == 0 )   return LOWERLEFT_CORNER;
		if( jbug == m-1 ) return LOWERRIGHT_CORNER;
	}
	
	fprintf(stderr, "error position\n");
	exit(EXIT_FAILURE);
}

int	allTileTouched(int **count, const int n, const int m)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if( count[i][j] == 0 ) return FALSE; // not all tiles was touched, return 0
	return TRUE; // all tiles was touched
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

void print(int** count, int n, int m, int totalMoves)
{
	FILE *outputFIle = fopen("Sample_Output.txt", "w");
	if( outputFIle == NULL )
	{
		fprintf(stderr, "cannot open Sample_Output.txt");
		exit(EXIT_FAILURE);
	}

	//(1) print the total number of legal moves
	fprintf(outputFIle, "總共%d步\r\n\r\n", totalMoves);
	
	//(2) print final count array
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			fprintf(outputFIle ,"%3d ", count[i][j]);
		fprintf(outputFIle, "\r\n");
	}
}

void freeCount(int** count, int n)
{
	for(int i = 0; i < n; ++i) 
		free(count[i]);  
	free(count); 
}
