/**
 *	DataSturctures
 *	hw1_1
 *	Ch1 Basic Concept
 *	Factorial
 *
 *	compile info : gcc hw1_1.c -o test -std=c99
 */

#include <stdio.h>

int recursiveFactorial(int); //recursive version of factorial
int iterativeFactorial(int); //iterative version of factorial

int main()
{
	for (;;)
	{
		int n;

		printf("Please enter a number bigger than 0, enter '-1' to end program.\n");
		scanf("%d", &n);

		if (n <= 1) { printf("1\n"); continue;}

		printf("iterative : %d\n", iterativeFactorial(n));
		printf("recursive : %d\n", recursiveFactorial(n));
	}
}


int recursiveFactorial(int n)
{
	if (n != 1)
		return n * recursiveFactorial(n - 1);
	else
		return 1;
}

int iterativeFactorial(int n)
{
	for (int i = n - 1; i != 1; --i)
		n = n * i;
	return n;
}
