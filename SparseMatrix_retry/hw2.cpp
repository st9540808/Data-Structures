//hw2.cpp

#include <iostream>
#include <iomanip>
using namespace std;


// SparseMatrix definition
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


// Sparse Matrix implementation
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
	SparseMatrix tempMatrix;
	tempMatrix = *this;
	colSize = tempMatrix.rowSize;
	rowSize = tempMatrix.colSize;
	
	// delete original matrix data
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
	rowHeadList = NULL;
	colHeadList = NULL;

	// reassign data
	for ( int i = 0; i < tempMatrix.rowSize; ++i )
	{
		const HeadNode *curRowHeadPtr = tempMatrix.rowHeadList;
		while ( curRowHeadPtr != NULL )
		{
			if ( curRowHeadPtr->entryHead->row == i )
				break;
			curRowHeadPtr = curRowHeadPtr->next;
		}
		
		if ( curRowHeadPtr != NULL )
			for ( int j = 0; j < tempMatrix.colSize; ++j )
			{
				EntryNode *curEntryPtr = curRowHeadPtr->entryHead;
				while ( curEntryPtr != NULL )
				{
					if ( curEntryPtr->col == j )
					{
						insertNode( curEntryPtr->value, j, i );
						break;
					}
					curEntryPtr = curEntryPtr->right;
				}
			}
	}
	return *this;
}


const SparseMatrix &SparseMatrix::operator=( const SparseMatrix &rhsMatrix )
{
	if ( &rhsMatrix != this )
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
	return *this;
}

const SparseMatrix SparseMatrix::operator*( const SparseMatrix &rhsMatrix )
{
	SparseMatrix outputMatrix;
	if ( colSize != rhsMatrix.rowSize || colSize == 0 || rhsMatrix.rowSize == 0 )
	{
		cout << "matries can't mutiply ( output an empty Sparse Matrix )\n";
		return outputMatrix;
	}

	outputMatrix.rowSize = rowSize;
	outputMatrix.colSize = rhsMatrix.colSize;

	for ( int i = 0; i < rowSize; ++i )
	{
		for ( int j = 0; j < rhsMatrix.colSize; ++j )
		{
			const HeadNode *curRowHeadPtr = rowHeadList,
			               *curColHeadPtr = rhsMatrix.colHeadList;
			
			// find left hand side rowHead ( if exists )
			while ( curRowHeadPtr != NULL )
			{
				if ( curRowHeadPtr->entryHead->row == i )
					break;
				curRowHeadPtr = curRowHeadPtr->next;
			}
			
			// find right hand side colHead ( if exists )
			while ( curColHeadPtr != NULL )
			{
				if ( curColHeadPtr->entryHead->col == j )
					break;
				curColHeadPtr = curColHeadPtr->next;
			}

			if ( curRowHeadPtr == NULL || curColHeadPtr == NULL )
				continue;
			
			// calculate c_ij
			int c_ij = 0;
			for ( int k = 0; k < colSize; ++k )
			{
				const EntryNode *curRowEntryPtr = curRowHeadPtr->entryHead,
				                *curColEntryPtr = curColHeadPtr->entryHead;
				
				// search for a(i,k) entry
				int a_ik = 0;
				for ( int traverse = 0; traverse <= k; ++traverse )
				{
					if ( curRowEntryPtr != NULL && curRowEntryPtr->col == k )
					{
						a_ik = curRowEntryPtr->value;
						break;
					}
					else if ( curRowEntryPtr != NULL )
						curRowEntryPtr = curRowEntryPtr->right;
					else 
						break;
				}
				
				// search for b(k,j) entry
				int b_kj = 0;
				for ( int traverse = 0; traverse <= k; ++traverse )
				{
					if ( curColEntryPtr != NULL && curColEntryPtr->row == k )
					{
						b_kj = curColEntryPtr->value;
						break;
					}
					else if ( curColEntryPtr != NULL )
						curColEntryPtr = curColEntryPtr->down;
					else 
						break;
				}
				c_ij += a_ik * b_kj;
			}
			if ( c_ij != 0 )
				outputMatrix.insertNode( c_ij, i, j );
		}
	}
	return outputMatrix;
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
				output << setw(4) << "0";
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
				cout << setw(4) << curEntryPtr->value;
				notFound = false;
			}
			curEntryPtr = curEntryPtr->right;
		}
		if ( notFound )
			cout << setw(4) << "0";
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




int main()
{
	SparseMatrix matrix_1;

	cin  >> matrix_1;
	cout << "matrix transposed\n" << matrix_1.transposed;

	return 0;
}
