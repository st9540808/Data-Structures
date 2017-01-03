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
	for (int i = 0; i < NumOfVertices; ++i)
	{
		ListNode *curNodePtr = adjList[i],
				 *tmpNodePtr;
		
		while (curNodePtr != NULL)
		{
			tmpNodePtr = curNodePtr;
			curNodePtr = curNodePtr->link;
			delete tmpNodePtr;
		}
	}
	
	delete [] adjList;
	delete [] inDegree;
}

void Graph::input(ifstream &inputGraph)
{
	// get the total number of vertices
	inputGraph >> NumOfVertices;
	if (NumOfVertices < 0)
	{
		cerr << "invalid number of vertice\n";
		exit(1);
	}

	// construct adjacent list
	adjList = new ListNode*[NumOfVertices];
	inDegree = new int[NumOfVertices];
	for (int i = 0; i < NumOfVertices; ++i)
	{
		adjList[i] = NULL;
		inDegree[i] = 0;
	}

	int inputDur;
	for (int i = 0; i < NumOfVertices; ++i)
		for (int j = 0; j < NumOfVertices; ++j)
		{
			inputGraph >> inputDur;
			if (inputDur > 0)
				addNode(i, j, inputDur);
		}
}

// i : tail node
// j : head node
void Graph::addNode(int i, int j, int dur)
{
	ListNode *newNode = new ListNode(j, dur);
	
	// add the new node to the end of the chain in adjList[i]
	if (adjList[i] == NULL)
		adjList[i] = newNode;
	else
	{
		ListNode *curNodePtr = adjList[i];
		
		while (curNodePtr->link != NULL)
			curNodePtr = curNodePtr->link;
		curNodePtr->link = newNode;
	}
}

void Graph::print()
{
	for (int i = 0; i < NumOfVertices; ++i)
	{
		cout << i << " : ";
		if (adjList[i] != NULL)
		{
			ListNode *curNodePtr = adjList[i];
			
			while (curNodePtr != NULL)
			{
				cout << "(";
				cout << curNodePtr->vertex << "," << curNodePtr->duration;
				cout << ") ";
				curNodePtr = curNodePtr->link;
			}
		}
		cout << endl;
	}
}
