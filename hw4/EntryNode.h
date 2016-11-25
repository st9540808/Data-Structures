//SparseMatrix's node definition
#ifndef ENTRY_NODE_H
#define ENTRY_NODE_H

class SparseMatrix;

class EntryNode
{
	friend SparseMatrix;
	
	public:
		EntryNode( const int &, const int &, const int & );
		int getValue() const;

	private:
		int row;
		int col;
		int value;
		EntryNode *down; //next node in the direction down
		EntryNode *right;//next node in the direction right
};


#endif
