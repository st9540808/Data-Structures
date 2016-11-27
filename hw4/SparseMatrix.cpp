// SparseMatrix Definition

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

SparseMatrix::SparseMatrix()
{

}

SparseMatrix::EntryNode::EntryNode( const int &inputValue, const int &inputRow, const int &inputCol )
	: value( inputValue ), row( inputRow ), col( inputCol ), down( NULL ), right( NULL )
{

}


SparseMatrix::~SparseMatrix()
{
	for ( const EntryNode *currentPtr : colHead )
		if ( currentPtr != NULL )
		{
			const EntryNode *tempPtr;
			while ( currentPtr != NULL )
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->down;
				delete tempPtr;
			}
		}
}


void SparseMatrix::print() const
{
	for ( int i = 0; i < rowHead.size(); ++i )
	{
		EntryNode *currentPtr = rowHead.at( i );

		while ( currentPtr != NULL )
		{
			cout << currentPtr->value << "("<< currentPtr->row << "," << currentPtr->col << ") ";
			currentPtr = currentPtr->right;
		}
		cout << "\n";
	}
}

const SparseMatrix &SparseMatrix::transpose()
{
	vector< EntryNode * > newRowHead( colHead.size(), NULL );
	vector< EntryNode * > newColHead( rowHead.size(), NULL );

	int row = 0, col;
	for ( EntryNode* const rowHeadItr : rowHead )
	{
		col = 0;
		for ( EntryNode* const colHeadItr : colHead )
		{	
			// locate element(row,col)	
			EntryNode *currentPtr = rowHeadItr; int value = 0;
			for ( int traverse = 0; traverse <= col; ++traverse )
			{
				if ( currentPtr != NULL && currentPtr->col == col )
				{	
					value = currentPtr->value;
					break;
				}
				else if ( currentPtr != NULL )
					currentPtr = currentPtr->right;
				else
					break;
			}
			
			if ( value != 0 )
				transposeNode( currentPtr, newRowHead, newColHead );
			++col; 
		}
		++row;
	}
	
	for ( const EntryNode *currentPtr : colHead )
		if ( currentPtr != NULL )
		{
			const EntryNode *tempPtr;
			while ( currentPtr != NULL )
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->down;
				delete tempPtr;
			}
		}

	colHead.clear(); rowHead.clear();
	rowHead = newRowHead;
	colHead = newColHead;
	
	return *this;
}


const SparseMatrix &SparseMatrix::operator=( const SparseMatrix& right )
{
	if ( &right != this )
	{
		// clear the maxtrix to be assigned
		for ( int i = 0; i < colHead.size(); ++i )
			if ( colHead.at( i ) != NULL )
			{
				EntryNode *currentPtr = colHead.at( i );
				EntryNode *tempPtr;
	
				while ( currentPtr != NULL )
				{
					tempPtr = currentPtr;
					currentPtr = currentPtr->down;
					delete tempPtr;
				}
			}
		rowHead.clear(); colHead.clear();

		// assign the matrix
		rowHead.resize( right.rowHead.size() );
		colHead.resize( right.colHead.size() );

		for ( int i = 0; i < colHead.size(); ++i )
		{
			// traverse the list in col(i)
			EntryNode *currentPtr = right.colHead.at( i );
			while ( currentPtr != NULL )
			{
				int row = currentPtr->row,
					col = currentPtr->col,
					value = currentPtr->value;
				
				insertNode( value, row, col );
				currentPtr = currentPtr->down;
			}
		}
	}
	return *this;
}

const SparseMatrix SparseMatrix::operator*( const SparseMatrix &matrix )
{
	SparseMatrix outputMatrix;
	if ( colHead.size() != matrix.rowHead.size() ) // if can't multiply
	{
		cout << "matries can't multiply ( return a empty Sparse Matrix )\n";
		return outputMatrix; // output a empty Sparse matrix
	}
	
	outputMatrix.rowHead.resize( rowHead.size() );
	outputMatrix.colHead.resize( matrix.colHead.size() );
	
	int row = 0, col;
	for ( EntryNode* const rowHeadItr : rowHead )
	{
		col = 0;
		for ( EntryNode* const colHeadItr : matrix.colHead )
		{
			int product = 0; // the value of product is the element c(i,j)
			for ( int k = 0; k < colHead.size(); ++k )
			{
				EntryNode *curRowPtr = rowHeadItr,
				          *curColPtr = colHeadItr;
				
				// search for a(i,k) entry
				int a_ik = 0;
				for ( int traverse = 0; traverse <= k; ++traverse )
				{
					if ( curRowPtr != NULL && curRowPtr->col == k )
					{	
						a_ik = curRowPtr->value;
						break;
					}
					else if ( curRowPtr != NULL )
						curRowPtr = curRowPtr->right;
					else
						break;
				}
			
				// search for b(k,j) entry
				int b_kj = 0;
				for ( int traverse = 0; traverse <= k; ++traverse )
				{
					if ( curColPtr != NULL && curColPtr->row == k )
					{	
						b_kj = curColPtr->value;
						break;
					}
					else if ( curColPtr != NULL )
						curColPtr = curColPtr->down;
					else
						break;
				}
				product += a_ik*b_kj;	
			}
			if ( product != 0 )
				outputMatrix.insertNode( product, row, col );
			++col;
		}
		++row;
	}
	return outputMatrix;
}


istream &operator>>( istream &input, SparseMatrix &matrix )
{
	int maxRow, maxCol;
	cin >> maxRow >> maxCol;

	matrix.rowHead.resize( maxRow, NULL );
	matrix.colHead.resize( maxCol, NULL );

	for ( int i = 0; i < matrix.rowHead.size(); ++i )
		for ( int j = 0; j < matrix.colHead.size(); ++j )
		{
			int inputValue;
			cin >> inputValue;
			
			if ( inputValue != 0 )
				matrix.insertNode( inputValue, i, j );
		}
}

ostream &operator<<( ostream &output, const SparseMatrix &matrix )
{
	for ( int i = 0; i < matrix.rowHead.size(); ++i )
	{
		for ( int j = 0; j < matrix.colHead.size(); ++j )
		{
			SparseMatrix::EntryNode *currentPtr = matrix.rowHead.at( i );
			
			int curTraversal = 0; bool notFound = true;
			while ( curTraversal <= j && currentPtr != NULL ) 
			{
				if ( currentPtr->col == j )
				{
					output << setw(4) << currentPtr->value;
					notFound = false;
					break;
				}
				currentPtr = currentPtr->right;
			}
			if ( notFound )
				output << setw(4) << "0";
		
		}
		output << "\n";
	}
	output << "\n";
}


void SparseMatrix::insertNode( const int &value, const int &row, const int &col )
{
	EntryNode *newPtr = new EntryNode( value, row, col );

	// connect with col head list
	if ( colHead.at( col ) == NULL )
		colHead.at( col ) = newPtr;
	else
	{
		EntryNode *tempPtr = colHead.at( col );

		while ( tempPtr->down != NULL )
			tempPtr = tempPtr->down;
		tempPtr->down = newPtr;
	}

	// connect with row head list
	if ( rowHead.at( row ) == NULL )
		rowHead.at( row ) = newPtr;
	else
	{
		EntryNode *tempPtr = rowHead.at( row );

		while ( tempPtr->right != NULL )
			tempPtr = tempPtr->right;
		tempPtr->right = newPtr;
	}
}

void SparseMatrix::transposeNode( EntryNode *transTargetPtr, vector< EntryNode * > &newRowHead, vector< EntryNode * > &newColHead )
{
	EntryNode *newPtr = new EntryNode( transTargetPtr->value, transTargetPtr->col, transTargetPtr->row );
	
	// connect with NEW col head list
	if ( newColHead.at( transTargetPtr->row ) == NULL )
		newColHead.at( transTargetPtr->row ) = newPtr;
	else
	{
		EntryNode *tempPtr = newColHead.at( transTargetPtr->row );

		while ( tempPtr->down != NULL )
			tempPtr = tempPtr->down;
		tempPtr->down = newPtr;
	}

	// connect with NEW row head list
	if ( newRowHead.at( transTargetPtr->col ) == NULL )
		newRowHead.at( transTargetPtr->col ) = newPtr;
	else
	{
		EntryNode *tempPtr = newRowHead.at( transTargetPtr->col );

		while ( tempPtr->right != NULL )
			tempPtr = tempPtr->right;
		tempPtr->right = newPtr;
	}	
}
