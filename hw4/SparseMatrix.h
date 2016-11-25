//SparseMatrix definition
#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H 

#include <iostream>
#include <vector>
#include "EntryNode.h"

class SparseMatrix
{
	public:
		SparseMatrix();
		~SparseMatrix();
		void inputMatrix();	//input row & col first, then input matrix
		void print() const;	//print out SparseMatrix

	private:
		std::vector< EntryNode * > rowHead;
		std::vector< EntryNode * > colHead;
		
		void insertNode( int &value, int row, int col );
};

#endif
