#include <iostream>
#include "ListNode.h"
#include "Graph.h"
using namespace std;

Graph::Graph()
	: adjList(NULL),
	  inDegree(NULL)
{
}

Graph::~Graph()
{
	delete [] adjList;
	delete [] inDegree;
}

void Graph::input(ifstream &inputGraph)
{
	// get the total number of vertices
	inputGraph >> NumOfVertices;
	cout << NumOfVertices;

	// construct adjacent list
	adjList = new ListNode*[NumOfVertices];
	inDegree = new int[NumOfVertices];
	for (int i = 0; i < NumOfVertices; ++i)
	{
		adjList[i] = NULL;
		inDegree[i] = 0;
	}

	for (int i = 0; i < NumOfVertices; ++i)
		for (int j = 0; j < NumOfVertices; ++j)
		{

		}
}

