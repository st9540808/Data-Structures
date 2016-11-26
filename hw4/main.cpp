//main.cpp

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix matrix_1, matrix_2, matrix_3;

	cin >> matrix_1;
	cout << matrix_1;
	cin >> matrix_2;
	cout << matrix_2;

	matrix_3 = matrix_1 * matrix_2;
	cout << matrix_3;
	return 0;
}
