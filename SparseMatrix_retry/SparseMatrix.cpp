// SparseMatrix implementation

#include <iostream>
#include "SparseMatrix.h"
using namespace std;


SparseMatrix::SparseMatrix()
	: rowHeadList( NULL ), 
	  colHeadList( NULL ), 
	  rowSize( 0 ), 
	  colSize( 0 )
{

}

SparseMatrix::EntryNode::EntryNode( const int &inputValue, const int &inputRow, const int &inputCol )
	: value( inputValue ), 
	  row( inputRow ), 
	  col( inputCol ), 
	  down( NULL ), 
	  right( NULL )
{

}

SparseMatrix::HeadNode::HeadNode()
	: next( NULL ),
	  entryHead( NULL )
{

}

SparseMatrix::~SparseMatrix()
{
	const HeadNode *curHeadPtr = colHeadList, *tempHeadPtr;
	while ( curHeadPtr != NULL )
	{
		const EntryNode *curEntryPtr = curHeadPtr->entryHead, *tempPtr;
		
		while ( curEntryPtr != NULL )
		{
			tempPtr = curEntryPtr;
			curEntryPtr = curEntryPtr->down;
			delete tempPtr;
		}	
		
		tempHeadPtr = curHeadPtr;
		curHeadPtr = curHeadPtr->next;
		delete tempHeadPtr;
	}
	
	curHeadPtr = rowHeadList;
	while ( curHeadPtr != NULL )
	{
		tempHeadPtr = curHeadPtr;
		curHeadPtr = curHeadPtr->next;
		delete tempHeadPtr;
	}
}

const SparseMatrix &SparseMatrix::transpose()
{
}


const SparseMatrix &SparseMatrix::operator=( const SparseMatrix& rhsMatrix )
{
	// delete original data
	const HeadNode *curHeadPtr = colHeadList, *tempHeadPtr;
	while ( curHeadPtr != NULL )
	{
		const EntryNode *curEntryPtr = curHeadPtr->entryHead, *tempPtr;
		
		while ( curEntryPtr != NULL )
		{
			tempPtr = curEntryPtr;
			curEntryPtr = curEntryPtr->down;
			delete tempPtr;
		}	
		
		tempHeadPtr = curHeadPtr;
		curHeadPtr = curHeadPtr->next;
		delete tempHeadPtr;
	}
	
	curHeadPtr = rowHeadList;
	while ( curHeadPtr != NULL )
	{
		tempHeadPtr = curHeadPtr;
		curHeadPtr = curHeadPtr->next;
		delete tempHeadPtr;
	}
	
	// assign new data
	rowSize = rhsMatrix.rowSize;
	colSize = rhsMatrix.colSize;
	rowHeadList = NULL;
	colHeadList = NULL;

	curHeadPtr = rhsMatrix.rowHeadList;
	while ( curHeadPtr != NULL )
	{
		const EntryNode *curEntryPtr = curHeadPtr->entryHead;

		while ( curEntryPtr != NULL )
		{
			insertNode( curEntryPtr->value, curEntryPtr->row, curEntryPtr->col );
			curEntryPtr = curEntryPtr->right;
		}
		curHeadPtr = curHeadPtr->next;
	}
}

const SparseMatrix SparseMatrix::operator*( const SparseMatrix &rhsMatrix )
{
}


istream &operator>>( istream &input, SparseMatrix &matrix )
{
	int maxRow, maxCol;
	input >> maxRow >> maxCol;

	matrix.rowSize = maxRow;
	matrix.colSize = maxCol;

	for ( int i = 0; i < maxRow; ++i )
	{
		for ( int j = 0; j < maxCol; ++j )
		{
			int inputValue;
			input >> inputValue;
			
			if ( inputValue != 0 )
				matrix.insertNode( inputValue, i, j );
		}
	}
}

ostream &operator<<( ostream &output, const SparseMatrix &matrix )
{
	for ( int i = 0; i < matrix.rowSize; ++i )
	{	
		const SparseMatrix::HeadNode *curHeadPtr = matrix.rowHeadList;
		int curTraveral = 0; bool notFound = true;
		
		while ( curHeadPtr != NULL && curTraveral <= i )
		{
			if ( curHeadPtr->entryHead->row == i )
			{	
				matrix.printColumn( curHeadPtr );
				notFound = false;
			}
			curHeadPtr = curHeadPtr->next;
		}
		if ( notFound )
			for ( int i = 0; i < matrix.colSize; ++i )
				output << setw(3) << "0";
		output << "\n";
	}
	output << endl;
}

void SparseMatrix::printColumn( const HeadNode *rowHead ) const
{
	for ( int i = 0; i < colSize; ++i )
	{	
		const EntryNode *curEntryPtr = rowHead->entryHead;
		int curTraveral = 0; bool notFound = true;
		
		while ( curEntryPtr != NULL && curTraveral <= i )
		{
			if ( curEntryPtr->col == i )
			{	
				cout << setw(3) << curEntryPtr->value;
				notFound = false;
			}
			curEntryPtr = curEntryPtr->right;
		}
		if ( notFound )
			cout << setw(3) << "0";
	}
}


void SparseMatrix::insertNode( const int &value, const int &row, const int &col )
{
	EntryNode * const newEntryPtr = new EntryNode( value, row, col );

	if ( colHeadList == NULL )// there is no entry in Sparse Matrix 
	{
		HeadNode * const newHeadPtr = new HeadNode;
		newHeadPtr->entryHead = newEntryPtr;
		colHeadList = newHeadPtr;
	}
	else
	{
		HeadNode *curHeadPtr = colHeadList;
		
		for ( int traverse = 0; traverse <= col; ++traverse )
		{
			if ( curHeadPtr != NULL && curHeadPtr->entryHead->col == col )
			{
				EntryNode *curEntryPtr = curHeadPtr->entryHead;
				
				while ( curEntryPtr->down != NULL )
					curEntryPtr = curEntryPtr->down;
				curEntryPtr->down = newEntryPtr;
				break;
			}
			else if ( curHeadPtr == NULL || traverse == col ) // if no entry in that column, new a head node
			{
				HeadNode * const newHeadPtr = new HeadNode;

				if ( colHeadList->entryHead->col > col )
				{
					newHeadPtr->next = colHeadList;
					colHeadList = newHeadPtr;
				}
				else
				{
					HeadNode *temp = colHeadList;
					
					while ( temp->next != NULL && temp->next->entryHead->col < col )
						temp = temp->next;
					newHeadPtr->next = temp->next;
					temp->next = newHeadPtr;
				}
		
				newHeadPtr->entryHead = newEntryPtr;
				break;
			}
			curHeadPtr = curHeadPtr->next;
		}
	}
	
	if ( rowHeadList == NULL )// there is no entry in Sparse Matrix 
	{
		HeadNode * const newHeadPtr = new HeadNode;
		newHeadPtr->entryHead = newEntryPtr;
		rowHeadList = newHeadPtr;
	}
	else
	{
		HeadNode *curHeadPtr = rowHeadList;
		
		for ( int traverse = 0; traverse <= row; ++traverse )
		{
			if ( curHeadPtr != NULL && curHeadPtr->entryHead->row == row )
			{
				EntryNode *curEntryPtr = curHeadPtr->entryHead;
				
				while ( curEntryPtr->right != NULL )
					curEntryPtr = curEntryPtr->right;
				curEntryPtr->right = newEntryPtr;
				break;
			}
			else if ( curHeadPtr == NULL || traverse == row )
			{
				HeadNode * const newHeadPtr = new HeadNode;

				if ( rowHeadList->entryHead->row > row )
				{
					newHeadPtr->next = rowHeadList;
					rowHeadList = newHeadPtr;
				}
				else
				{
					HeadNode *temp = rowHeadList;
					
					while ( temp->next != NULL && temp->next->entryHead->row < row )
						temp = temp->next;
					newHeadPtr->next = temp->next;
					temp->next = newHeadPtr;
				}
		
				newHeadPtr->entryHead = newEntryPtr;
				break;
			}
			curHeadPtr = curHeadPtr->next;
		}
	}
}

void SparseMatrix::transposeNode( EntryNode *transTargetPtr, vector< EntryNode * > &newRowHead, vector< EntryNode * > &newColHead )
{
}
