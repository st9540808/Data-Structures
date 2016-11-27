//main.cpp

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix matrix;
	
	cin >> matrix;
	cout << "matrix_3 (transposed) : \n" << matrix.transpose();
	
	return 0;
}
