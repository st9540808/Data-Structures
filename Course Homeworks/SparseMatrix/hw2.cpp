/**
 *	assignment 4 - hw2
 *	Sparse Matrix transpose
 *	
 *	Data-Sructures
 *	CH4 linked list p.178
 */

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix inputMatrix;
	
	cin >> inputMatrix;
	cout << "inputMatrix after transposed : \n" << inputMatrix.transpose();
	
	return 0;
}
