//SparseMatrix Definition

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

SparseMatrix::SparseMatrix()
{

}

SparseMatrix::~SparseMatrix()
{
	for ( int i = 0; i < colHead.size(); ++i )
		if ( colHead.at( i ) != NULL )
		{
			cout << "destoring nodes in col(" << i <<")\n";

			EntryNode *currentPtr = colHead.at( i );
			EntryNode *tempPtr;

			while ( currentPtr != NULL )
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->down;
				cout << tempPtr->value << " ";
				delete tempPtr;
			}
			cout << "\n\n";
		}
}

void SparseMatrix::inputMatrix()
{
	int maxRow, maxCol;
	cin >> maxRow >> maxCol;

	rowHead.resize( maxRow, NULL );
	colHead.resize( maxCol, NULL );

	for ( int i = 0; i < rowHead.size(); ++i )
		for ( int j = 0; j < colHead.size(); ++j )
		{
			int inputValue;
			cin >> inputValue;
			
			if ( inputValue != 0 )
				insertNode( inputValue, i, j );
		}
	print();
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

void SparseMatrix::print() const
{
	for ( int i = 0; i < rowHead.size(); ++i )
	{
		EntryNode *currentPtr = rowHead.at( i );

		while( currentPtr != NULL )
		{
			cout << currentPtr->value << " ";
			currentPtr = currentPtr->right;
		}
		cout << "\n";
	}
}
