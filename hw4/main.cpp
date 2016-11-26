//main.cpp

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix matrix_1, matrix_2;

	cin >> matrix_1;
	cout << matrix_1;
	cin >> matrix_2;

	matrix_1 = matrix_2;
	cout << matrix_1;
	return 0;
}
