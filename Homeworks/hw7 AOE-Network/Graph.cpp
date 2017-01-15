// utility function of AOE Network

#include <iostream>
#include <stack>
#include "ListNode.h"
#include "Graph.h"
using namespace std;

bool Graph::isDAG()
{
	bool is_DAG = false;

	return is_DAG;
}

vector<int> Graph::topologicalSort()
{
	vector<int> order;
	stack<int> verticesStack;

	// gather all vertices with no predecessors (ie inDegree[i] == 0)
	for (int i = 0; i < V; ++i)
		if (inDegree[i] == 0)
			verticesStack.push(i);

	for (int i = 0; i < V; ++i)
	{
		if (inDegree[i] == -1)
		{
			cerr << "input Graph in not a DAG (directed acyclic graph)"
			     << "program terminated.\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			
		}
	}

	return order;
}


/**
 * basic method of Graph
 * including :
 * +input()  -input a AOE Network and build adjacent list
 * +print()  -print out in degree for every vertices and adjacent list
 */
Graph::Graph()
	: V(0) {} // also creating vector of size 0

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
	adjList.resize(V, NULL);
	inDegree.resize(V, 0);

	int inputDur;
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
		{
			inputGraph >> inputDur;
			if (inputDur > 0)
			{
				addNode(i, j, inputDur);
				++inDegree.at(j);
			}
		}
}

// i : tail node
// j : head node
void Graph::addNode(int i, int j, int dur)
{
	ListNode *newNode = new ListNode(j, dur);

	// add the new node to the end of the chain in adjList[i]
	if (adjList.at(i) == NULL)
		adjList.at(i) = newNode;
	else
	{
		ListNode *curNodePtr = adjList.at(i);

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
		if (adjList.at(i) != NULL)
		{
			ListNode *curNodePtr = adjList[i];

			cout << inDegree.at(i) << " | " << i;
			while (curNodePtr != NULL)
			{
				cout << " -> (";
				cout << curNodePtr->vertex << "," << curNodePtr->duration;
				cout << ")";
				curNodePtr = curNodePtr->link;
			}
		}
		else
			cout << inDegree.at(i) << " | " << i;
		cout << endl;
	}
}
