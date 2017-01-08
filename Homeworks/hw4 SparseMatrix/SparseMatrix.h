// SparseMatrix definition
#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H 

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


class SparseMatrix
{
	class EntryNode;
	class HeadNode;
		
	friend ostream &operator<<( ostream &output, const SparseMatrix & ); // input a Sparse Matrix
	friend istream &operator>>( istream &output, SparseMatrix & ); // output Sparse Matrix ( with "0" entries )

public:
	SparseMatrix();
	~SparseMatrix();
	const SparseMatrix &transpose(); // tranpose a Sparse Matrix 
	const SparseMatrix &operator=( const SparseMatrix & );		
	const SparseMatrix  operator*( const SparseMatrix & ); // matrix multiplication

private:
	HeadNode *rowHeadList;
	HeadNode *colHeadList;
	int rowSize;
	int colSize;
	void printColumn  ( const HeadNode * ) const;
	void insertNode   ( const int &, const int &, const int & ); // add a node to the end of the list


	class EntryNode
	{
		friend SparseMatrix;
		friend ostream &operator<<( ostream &output, const SparseMatrix & );
		
	public:
		EntryNode( const int &, const int &, const int & );
	
	private:
		const int row;
		const int col;
		const int value;
		EntryNode *down; // next node in the direction down
		EntryNode *right;// next node in the direction right
	};
	
	class HeadNode
	{
		friend SparseMatrix;
		friend ostream &operator<<( ostream &output, const SparseMatrix & );
		
		public:
			HeadNode();
		
		private:
			HeadNode  *next;
			EntryNode *entryHead;
	};
};

#endif
