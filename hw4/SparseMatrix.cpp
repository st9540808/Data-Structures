//SparseMatrix Definition

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

const SparseMatrix &SparseMatrix::operator=( const SparseMatrix & right )
{
	if ( &right != this )
	{
		//clear the maxtrix to be assigned
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

		//assign the matrix
		rowHead.resize( right.rowHead.size() );
		colHead.resize( right.colHead.size() );

		for ( int i = 0; i < colHead.size(); ++i )
		{
			//traverse the list in col(i)
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
			
			int curTraversal = 0, notFound = true;
			while ( curTraversal <= j && currentPtr != NULL ) 
			{
				if ( currentPtr->col == j )
				{
					output << currentPtr->value << " ";
					notFound = false;
					break;
				}
				currentPtr = currentPtr->right;
			}
			if ( notFound )
				output << "0 ";
		
		}
		output << "\n";
	}
	output << "\n";
}


void SparseMatrix::insertNode( int &value, int row, int col )
{
	EntryNode *newPtr = new EntryNode( value, row, col );

	//connect with col head list
	if ( colHead.at( col ) == NULL )
		colHead.at( col ) = newPtr;
	else
	{
		EntryNode *tempPtr = colHead.at( col );

		while ( tempPtr->down != NULL )
			tempPtr = tempPtr->down;
		tempPtr->down = newPtr;
	}

	//connect with row head list
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
