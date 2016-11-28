/**
 *	assignment 4 - hw1
 *	Sparse Matrix multiplcation
 *	
 *	Data-Sructures
 *	CH4 linked list p.178
 */

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix inputMatrix_1, inputMatrix_2, output;

	cin >> inputMatrix_1; 
	cin >> inputMatrix_2;

	output = inputMatrix_1 * inputMatrix_2;
	cout << "output = inputMatrix_1 * inputMatrix_2\n";
	cout << "output : \n" << output;

	return 0;
}
