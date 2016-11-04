/**
 *	DataSturctures
 *	hw3_1
 *	Ch3 Stacks And Queues 
 *	p.120 A "mazing" problem
 *	
 *	compile info : gcc hw3_1.c -o test -std=c99
 */
 
#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0

typedef struct {
	short int row;
	short int col;
	short int direction;
} element;

typedef struct{
	short int vertical;
	short int horizontal;
} offsets;

const offsets move[8] = {
	{-1, 0},//N
	{-1, 1},//NE
	{ 0, 1},//E
	{ 1, 1},//SE
	{ 1, 0},//S
	{ 1,-1},//SW
	{ 0,-1},//W
	{-1,-1},//NW
};


void solveMaze();
void readIn(int *n, int *m, int *startRow, int *startCol, int *desRow, int *desCol);
void getPosition(FILE *input, char target, int *row, int *col);
void checkValidPosition(FILE *input, int n, int m, int row, int col, char name[]);//assume s & d in not in the middle of maze

int main()
{
	solveMaze();
	return 0;
}

void solveMaze()
{
	int n = 0, m = 0,
		startRow, startCol,//start position
		desRow, desCol;//destination position
	readIn(&n,  &m);
	char **maze = initializeMaze(n+2, m+2);
	for(int i = 0; i < n+2; ++i)
	{
		for(int j = 0; j < m+2; ++j)
			printf("%d ",maze[i][j]);
		printf("\n");
	}


}



void readIn(int *n, int *m, int *startRow, int *startCol, int *desRow, int *desCol)
{
	FILE *input = fopen("in.txt", "r");
	if( input == NULL ){
		fprintf(stderr, "cannot open in.txt");
		exit(EXIT_FAILURE);
	}
	
	//get m size
	char temp;
	while( fscanf(input, "%c", &temp) != EOF )
	{
		if( temp == '\r' )
			break;
		++*m;
	}

	//get n size
	rewind(input);
	while( fscanf(input, "%c", &temp) != EOF )
		if( temp == '\n' )
			++*n;
	++*n;
	
	//get s position
	getPosition(input, 's', startRow, startCol);
//	checkValidPosition(input, *n, *m, *startRow, *startCol, "start");
	

	//get d position
	getPosition(input, 'd', desRow, desCol);
//	checkValidPosition(input, *n, *m, *desRow, *desCol, "destination");
	
	
	fclose(input);
}

void getPosition(FILE *input, char target, int *row, int *col)
{
	rewind(input);
	char temp;
	while( fscanf(input, "%c", &temp) != EOF )
	{
		static int i = 0, j = 0;
		if( temp == target )
		{
			*row = i;
			*col = j;
			break;
		}
		else if( temp == '\r' )//when reach to a carriage return, advance to next row
		{
			++i;
			j = 0;
		}
		else if( temp != '\n' )
			++j;
	}
}

void checkValidPosition(FILE *input, int n, int m, int row, int col, char name[])
{
	if( (row < n-1 && row > 0) && (col < m-1 && col > 0) )
	{
		fprintf(stderr, "error %s position\n", name);
		fclose(input);
		exit(EXIT_FAILURE);
	}
}


char** initializeMaze(int n, int m)
{
	FILE *input = fopen("in.txt", "r");
	if( input == NULL ){
		fprintf(stderr, "cannot open in.txt");
		exit(EXIT_FAILURE);
	}
	
	char **maze;
	count = malloc(n * sizeof(char *)); //n rows
	for(int i = 0; i < n; ++i)
	{
		maze[i] = calloc(m , sizeof(char)); //m columns
		if(count[i] == NULL){
			fprintf(stderr, "out of memory\n");
			exit(EXIT_FAILURE);
		}
	}	
	
	fclose(input);
	return maze;
}
