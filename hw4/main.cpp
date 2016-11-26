//main.cpp

#include <iostream>
#include "SparseMatrix.h"

int main()
{
	SparseMatrix matrix1;
	matrix1.inputMatrix();

	std::cout << matrix1;

	return 0;
}
