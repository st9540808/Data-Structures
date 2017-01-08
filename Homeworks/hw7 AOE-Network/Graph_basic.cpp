/**
 * basic method of Graph
 * including :
 * +input()  -input a AOE Network and build adjacent list
 * +print()  -print out in degree for every vertices and adjacent list
 */

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
	for (int i = 0; i < V; ++i)
	{
		ListNode *curNodePtr = adjList[i], *tmpNodePtr;

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
	inputGraph >> V;
	if (V < 0)
	{
		cerr << "invalid number of vertice\n";
		exit(1);
	}

	// construct adjacent list
	adjList = new ListNode*[V];
	inDegree = new int[V];
	for (int i = 0; i < V; ++i)
	{
		adjList[i] = NULL;
		inDegree[i] = 0;
	}

	int inputDur;
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
		{
			inputGraph >> inputDur;
			if (inputDur > 0)
			{
				addNode(i, j, inputDur);
				++inDegree[j];
			}
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
	cout << "format : (vertex, duration)\n";
	for (int i = 0; i < V; ++i)
	{
		if (adjList[i] != NULL)
		{
			ListNode *curNodePtr = adjList[i];

			cout << inDegree[i] << " | " << i;
			while (curNodePtr != NULL)
			{
				cout << " -> (";
				cout << curNodePtr->vertex << "," << curNodePtr->duration;
				cout << ")";
				curNodePtr = curNodePtr->link;
			}
		}
		else
			cout << inDegree[i] << " | " << i;
		cout << endl;
	}
}
