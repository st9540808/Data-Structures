#include <iostream>
#include "EntryNode.h"

EntryNode::EntryNode( const int &inputValue, const int &inputRow, const int &inputCol )
	: value( inputValue ), row( inputRow ), col( inputCol ), down( NULL ), right( NULL )
{

}

