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
		
	friend ostream &operator<<( ostream &output, const SparseMatrix & ); // input a Sparse Matrix
	friend istream &operator>>( istream &output, SparseMatrix & ); // output Sparse Matrix ( with "0" entries )

public:
	SparseMatrix();
	~SparseMatrix();
	void print() const;	// print out SparseMatrix ( without "0" entries )
	void transpose();

	const SparseMatrix &operator=( const SparseMatrix & );		
	const SparseMatrix  operator*( const SparseMatrix & ); // matrix multiplication

private:
	vector< EntryNode * > rowHead;
	vector< EntryNode * > colHead;
	void insertNode   ( const int &, const int &, const int & ); // add a node to the end of the list
	void transposeNode( EntryNode * , vector< EntryNode * > &, vector< EntryNode * > & );
	
	class EntryNode
	{
		friend SparseMatrix;
		friend ostream &operator<<( ostream &output, const SparseMatrix & );
		
	public:
		EntryNode( const int &, const int &, const int & );
	
	private:
		int row;
		int col;
		int value;
		EntryNode *down; // next node in the direction down
		EntryNode *right;// next node in the direction right
	};
};

#endif
