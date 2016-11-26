//SparseMatrix definition
#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H 

#include <iostream>
#include <vector>
#include <iomanip>
#include "EntryNode.h"
using namespace std;


class SparseMatrix
{
public:
	SparseMatrix();
	~SparseMatrix();
	void inputMatrix();	//input row & col first, then input matrix
	void print() const;	//print out SparseMatrix

	friend ostream &operator<<( ostream &output, const SparseMatrix & );

private:
	vector< EntryNode * > rowHead;
	vector< EntryNode * > colHead;
	
	void insertNode( int &value, int row, int col );
};

#endif
