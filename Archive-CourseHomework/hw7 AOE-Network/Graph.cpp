// utility function of AOE Network
#include <iostream>
#include <iomanip>
#include <stack>
#include "ListNode.h"
#include "Graph.h"
using namespace std;

vector<int> Graph::topologicalSort()
{
	vector<int> order; // topological order
	vector<int> earliestEventTime(adjList.size(), 0);
	vector<int> latestEventTime(adjList.size(), 0);
	stack<int> verticesStack;

	// gather all vertices with no predecessors (ie inDegree[i] == 0)
	for (decltype(inDegree.size()) i = 0; i < inDegree.size(); ++i)
		if (inDegree.at(i) == 0)
		{	
			verticesStack.push(i);
			inDegree.at(i) = -1;
		}
	
	// do topological sort and calculate earliest event time in paraelle
	for (decltype(adjList.size()) i = 0; i < adjList.size(); ++i)
		if (verticesStack.empty() == true)
		{
			cerr << "input Graph in not a DAG (directed acyclic graph)\n"
			     << "program terminated.\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			int j = verticesStack.top();
			verticesStack.pop();
			order.push_back(j);
			for (auto ptr = adjList.at(j); ptr != NULL; ptr = ptr->link)
			{
				int k = ptr->vertex;
				if (earliestEventTime.at(k) < earliestEventTime.at(j) + ptr->duration)
					earliestEventTime.at(k) = earliestEventTime.at(j) + ptr->duration;
				--inDegree.at(k);
				if (inDegree.at(k) == 0)
				{
					verticesStack.push(k);
					inDegree.at(k) = -1;
				}
			}
		}
	
	// calculate early time
	int activityIndex = 0;
	for (decltype(adjList.size()) i = 0; i < adjList.size(); ++i)
	{
		auto ptr = adjList.at(i);
		while (ptr != NULL)
		{
			earlyTime.at(activityIndex) = earliestEventTime.at(i);
			++activityIndex;
			ptr = ptr->link;
		}
	}

	// calculate latest event time
	for (auto i = order.rbegin(); i != order.rend(); ++i)
		if (adjList.at(*i) == NULL)
			latestEventTime.at(*i) = earliestEventTime.at(*i);
		else
		{
			auto ptr = adjList.at(*i);
			latestEventTime.at(*i) = latestEventTime.at(ptr->vertex) - ptr->duration;
			while (ptr = ptr->link, ptr != NULL)
				if (latestEventTime.at(ptr->vertex) - ptr->duration < latestEventTime.at(*i))
					latestEventTime.at(*i) = latestEventTime.at(ptr->vertex) - ptr->duration;
		}
	
	// calculate latest time
	activityIndex = 0;
	for (auto ptr : adjList)
		while (ptr != NULL)
		{
			lateTime.at(activityIndex) = latestEventTime.at(ptr->vertex) - ptr->duration;
			++activityIndex;
			ptr = ptr->link;
		}
	
	return order;
}

void Graph::printEssential()
{
	cout << setw(13) << "earlyTime|" 
		 << setw(12) << "lateTime|" 
		 << setw(9)  << "slack|" 
		 << setw(12) << "critical|" << endl;
	for (decltype(earlyTime.size()) i = 0; i < earlyTime.size(); ++i)
	{
		cout << 'a' << i+1;
		if (i+1 < 10)
		{
			cout << setw(10) << earlyTime.at(i) << "|"
				 << setw(11) << lateTime.at(i) << "|"
				 << setw(8)  << lateTime.at(i) - earlyTime.at(i) << "|";
			cout << setw(12) <<(lateTime.at(i) - earlyTime.at(i) == 0 
					? "Yes|" : "No|") << endl;
		}
		else if (i+1 < 100 and i+1 >= 10)
		{
			cout << setw(9) << earlyTime.at(i) << "|"
				 << setw(11) << lateTime.at(i) << "|"
				 << setw(8)  << lateTime.at(i) - earlyTime.at(i) << "|";
			cout << setw(12) <<(lateTime.at(i) - earlyTime.at(i) == 0 
					? "Yes|" : "No|") << endl;
		}
	}
}

/**
 * basic method for Graph
 * including :
 * -addNode() --add the node into adjacent list
 * +input()  --input a AOE Network and build adjacent list
 * +print()  --print out in degree for every vertices and adjacent list
 */
Graph::Graph() 
{
} // also creating vector of size 0

Graph::~Graph()
{
	for (auto curNodePtr: adjList)
		while (curNodePtr != NULL)
		{
			auto tmpNodePtr = curNodePtr;
			curNodePtr = curNodePtr->link;
			delete tmpNodePtr;
		}
}

void Graph::input(ifstream &inputGraph)
{
	// get the total number of vertices
	int numOfVertices;
	inputGraph >> numOfVertices;
	if (numOfVertices < 0)
	{
		cerr << "invalid number of vertice\n";
		exit(1);
	}

	// construct adjacent list
	adjList.resize(numOfVertices, NULL);
	inDegree.resize(numOfVertices, 0);

	int inputDur;
	for (decltype(adjList.size()) i = 0; i < adjList.size(); ++i)
		for (decltype(adjList.size()) j = 0; j < adjList.size(); ++j)
		{
			inputGraph >> inputDur;
			if (inputDur > 0) // skip negative duration
			{
				addNode(i, j, inputDur);
				++inDegree.at(j);
				earlyTime.push_back(0), lateTime.push_back(0);
			}
		}
}

// i : tail node, j : head node
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
	for (decltype(adjList.size()) i = 0; i < adjList.size(); ++i)
	{
		if (adjList.at(i) != NULL)
		{
			ListNode *curNodePtr = adjList.at(i);

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
