//SparseMatrix's node definition
#ifndef ENTRY_NODE_H
#define ENTRY_NODE_H

class SparseMatrix;

class EntryNode
{
	friend SparseMatrix;
	friend std::ostream &operator<<( std::ostream &output, const SparseMatrix & );
	
public:
	EntryNode( const int &, const int &, const int & );
	int getValue() const;
	int getRow() const;
	int getCol() const;

private:
	int row;
	int col;
	int value;
	EntryNode *down; //next node in the direction down
	EntryNode *right;//next node in the direction right
};


#endif
