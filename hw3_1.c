/**
 *	DataSturctures
 *	hw3_1
 *	Ch3 Stacks And Queues 
 *	p.120 A "mazing" problem
 *	
 *	the program print out all possible solution path (using depth first search)
 *	but doesn't guarantee to be the shortest path
 *
 *	compile info : gcc hw3_1.c -o test -std=c99
 */
 
#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
#define MAX_STACK_SIZE 300
typedef struct{
	int vert;
	int horiz;
} offsets;

const offsets move[8] = {
	{-1, 0}, //0 N
	{-1, 1}, //1 NE
	{ 0, 1}, //2 E
	{ 1, 1}, //3 SE
	{ 1, 0}, //4 S
	{ 1,-1}, //5 SW
	{ 0,-1}, //6 W
	{-1,-1}, //7 NW
};


//stack
typedef struct {
	int row;
	int col;
	int dir;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

//stack function
void push(element item);
element pop();
void stackFull();
element stackEmpty();


void solveMaze();
void findPath(char **maze, char **mark, int n, int m, int startRow, int startCol, int desRow, int desCol);

void recordSolutionPath(FILE* output, char **maze, int n, int m);
void readIn(int *n, int *m); //get n m size
void getPosition(char **maze, int n, int m, char target, int *row, int *col); //get start & destination postition
char** initializeMaze(int n, int m); //initialize maze array
char** initializeMark(int n, int m);


void printOut(char **array, int n, int m);


int main()
{
	solveMaze();
	return 0;
}



//stack function
void push(element item)
{
	if( top >= MAX_STACK_SIZE )
		stackFull();
	stack[++top] = item;
}

element pop()
{
	if( top == -1 )
		return stackEmpty();
	return stack[top--];
}

void stackFull()
{
	fprintf(stderr, "stack is full\n");
	exit(EXIT_FAILURE);
}

element stackEmpty()
{
	element error = {-1, -1, -1};
	fprintf(stderr, "stack is empty\n");
	return error;
}


//Maze solving function
void solveMaze()
{
	FILE* output = fopen("out.txt", "w");
	if( output == NULL ){
		fprintf(stderr, "cannot open out.txt");
		exit(EXIT_FAILURE);
	}

	int n = 0, m = 0,
		startRow, startCol, //start position
		desRow, desCol; //destination position
	
	//initialize all varible
	readIn(&n, &m);
	n = n + 2; m = m + 2;
	char **maze = initializeMaze(n, m),
		 **mark = initializeMark(n, m);
	getPosition(maze, n, m, 's', &startRow, &startCol);
	getPosition(maze, n, m, 'd', &desRow, &desCol);
	
	
	//initialize to the start position
	element position = {startRow, startCol, -1};
	push(position);
	mark[position.row][position.col] = '1';


	//find all possible route
	while(1)
	{	
		static int steps = 0, noRoute = TRUE;
		
		findPath(maze, mark, n, m, startRow, startCol, desRow, desCol);	
		if( top != -1 )
		{
			for(int i = 1; i <= top; ++i)
			{	
				maze[ stack[i].row ][ stack[i].col ] = '*';
				++steps;
			}
			//store solution path
			recordSolutionPath(output, maze, n, m);
			fprintf(output, "steps : %d\r\n\r\n", steps+1);
			
			for(int i = 1; i <= top; ++i)
				maze[ stack[i].row ][ stack[i].col ] = '0';
			steps = 0;
			noRoute = FALSE;
		}
		else if( noRoute == TRUE )
		{
			fprintf(output ,"No route");
			break;
		}
		else
			break;
	}

	fclose(output);
	for(int i = 0; i < n; ++i) 
	{
		free(maze[i]);  
		free(mark[i]);
	}
	free(maze);
	free(mark);
}

void findPath(char **maze, char **mark, int n, int m, int startRow, int startCol, int desRow, int desCol)
{
	int curRow, curCol, nextRow, nextCol, dir, pathFound = FALSE;
	while( top != -1 && pathFound != TRUE )
	{
		element position = pop();
		curRow = position.row; curCol = position.col; dir = position.dir + 1;
		while( dir <= 7 && pathFound != TRUE )
		{
			nextRow = curRow + move[dir].vert;
			nextCol = curCol + move[dir].horiz;
			if( nextRow == desRow && nextCol == desCol )
			{
				position.row = curRow; position.col = curCol; position.dir = dir;
				push(position);
				pathFound = TRUE;
				break;
			}
			else if( maze[nextRow][nextCol] != '1' && mark[nextRow][nextCol] != '1' )
			{
				mark[nextRow][nextCol] = '1';
				position.row = curRow; position.col = curCol; position.dir = dir;//save current position
				push(position);
				curRow = nextRow; curCol = nextCol; dir = 0;
			}
			else
				++dir;
		}
		if( pathFound != TRUE )
			mark[curRow][curCol] = '0';
	}
}

void recordSolutionPath(FILE* output, char **maze, int n, int m)
{
	fseek(output, 0L, SEEK_END);
	for(int i = 1; i < n-1; ++i)
	{
		for(int j = 1; j < m-1; ++j)
			fprintf(output, "%c",maze[i][j]);
		fprintf(output, "\r\n");
	}
}


void readIn(int *n, int *m)
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
	
	fclose(input);
}

void getPosition(char **maze, int n, int m, char target, int *row, int *col)
{
	for(int i = 1; i < n-1; ++i)
		for(int j = 1; j < m-1; ++j)
			if( maze[i][j] == target )
			{
				*row = i;
				*col = j;
				return;
			}
}

char** initializeMaze(int n, int m)
{
	FILE *input = fopen("in.txt", "r");
	if( input == NULL ){
		fprintf(stderr, "cannot open in.txt");
		exit(EXIT_FAILURE);
	}
	
	char **maze, temp;
	maze = malloc(n * sizeof(char *)); //n rows
	for(int i = 0; i < n; ++i)
	{
		maze[i] = malloc(m * sizeof(char)); //m columns
		if(maze[i] == NULL){
			fprintf(stderr, "out of memory\n");
			exit(EXIT_FAILURE);
		}
	}	
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{	
			if( !(i < n-1 && i > 0) || !(j < m-1 && j > 0) )//create boundary
				maze[i][j] = '1';
			else
			{
				do
				{
					fscanf(input, "%c", &temp);
					maze[i][j] = temp;
				}while( temp == '\n' || temp == '\r' );
			}
		}
	fclose(input);
	return maze;
}

char** initializeMark(int n, int m)
{
	char **mark, temp;
	mark = malloc(n * sizeof(char *)); //n rows
	for(int i = 0; i < n; ++i)
	{
		mark[i] = malloc(m * sizeof(char)); //m columns
		if(mark[i] == NULL){
			fprintf(stderr, "out of memory\n");
			exit(EXIT_FAILURE);
		}
	}	
	
	for(int i = 0; i < n; ++i)
		for(int j = 0 ; j < m; ++j)
			if( !(i < n-1 && i > 0) || !(j < m-1 && j > 0) )//create boundary
				mark[i][j] = '1';
			else
				mark[i][j] = '0';
	return mark;
}



void printOut(char **array, int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			printf("%c ",array[i][j]);
		printf("\n");
	}
}
