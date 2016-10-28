/**
 *	DataSturctures
 *	hw2_1
 *	Ch2 Aarray and Structures 
 *	p.102 #7(c) generalized band matrix(Sparse Matrix)
 *	
 *	compile info : gcc hw2_1.c -o test -std=c99
 */

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, size)								\
	if( (p = malloc(size)) == NULL )				\
	{												\
		fprintf(stderr, "insufficient memory\n");	\
		exit(EXIT_FAILURE);							\
	}

#define REALLOC(p, size)							\
	if( (p = realloc(p, size)) == NULL )			\
	{												\
		fprintf(stderr, "insufficient memory'\n");	\
		exit(EXIT_FAILURE);							\
	}

//Sparse Matrix Terms
struct terms
{
	int row;
	int col;
	int value;
} *matrix;


void readFile(); 
void valueFuc(const int n, const int a, const int b, const int nElement, int e[nElement]);


int main()
{
	readFile();
	return 0;
}


void readFile()
{
	int value, n, a = 3, b = 3, nElement = 0; 
	
	char inputFileName[30];
	printf("please input the file name : ");
	scanf("%s", inputFileName);
	FILE *inputFile = fopen(inputFileName, "r");
	if( inputFile == NULL )
	{
		fprintf(stderr, "cannot open Sample_Output.txt");
		exit(EXIT_FAILURE);
	}
		
	fscanf(inputFile, "%d", &n);
	printf("a : ");
	scanf("%d",&a);
	printf("b : ");
	scanf("%d",&b);
	for(int i = 0; i < n; ++i)
	{
//		printf("\n");
		for(int j = 0; j < n; ++j)
		{
			fscanf(inputFile, "%d", &value);
			if( j > i-a && j < i+b )
			{
				if( nElement == 0 )	{ MALLOC(matrix, 1 * sizeof(struct terms));}
				else				{ REALLOC(matrix, (nElement + 1) * sizeof(struct terms));}
				
				matrix[nElement].row = i;
				matrix[nElement].col = j;
				matrix[nElement].value = value;

//				printf("%d (%d,%d) | ", matrix[nElement].value, matrix[nElement].row, matrix[nElement].col);
				++nElement;
			}
		}
	}
//	printf("total element : %d \n", nElement);
	
	int e[nElement];
	for(int i = 0; i < nElement; ++i) e[i] = -1;
	valueFuc(n, a, b, nElement, e);
	
	fclose(inputFile);
	free(matrix);
}


void valueFuc(const int n, const int a, const int b, const int nElement, int e[nElement])
{
	int eCurrent = 0;
	printf("\n");	
	{
		static int iteration = 0;
		for(int i = a-1; i > 0; i = (a-1)-iteration)
		{
			for(int j = 0; i != n; ++i, ++j)
			{
				for(int element = 0; element < nElement; ++element)
					if( matrix[element].row == i && matrix[element].col == j )
					{	
						e[eCurrent] = matrix[element].value;
						printf("e[%2d] = %d  d(%d,%d)\n", eCurrent, matrix[element].value, matrix[element].row, matrix[element].col);
						break;	
					}
				++eCurrent;
			}
			++iteration;
		}
	}
	
	for(int i = 0; i < n; ++i)
    {
		for(int element = 0; element < nElement; ++element)
			if( matrix[element].row == i && matrix[element].col == i )
			{	
				e[eCurrent] = matrix[element].value;
				printf("e[%2d] = %d  d(%d,%d)\n", eCurrent, matrix[element].value, matrix[element].row, matrix[element].col);
				break;	
			}
		++eCurrent;
	}
	
	{
		static int iteration = 0;
		for(int j = 1; j < b ; j = 1+iteration)
		{
			for(int i = 0; j != n; ++i, ++j)
			{
				for(int element = 0; element < nElement; ++element)
					if( matrix[element].row == i && matrix[element].col == j )
					{	
						e[eCurrent] = matrix[element].value;
						printf("e[%2d] = %d  d(%d,%d)\n", eCurrent, matrix[element].value, matrix[element].row, matrix[element].col);
						break;	
					}
				++eCurrent;
			}
			++iteration;
		}
	}
}