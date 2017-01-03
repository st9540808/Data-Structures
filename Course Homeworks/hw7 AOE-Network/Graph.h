#ifndef Graph_H
#define Graph_H

#include <fstream>
#include "ListNode.h"
using namespace std;

class Graph
{
public:
	Graph();
	~Graph();
	void input(ifstream &); //construct the graph representation(adjacent list)
	void print();

private:
	void addNode(int, int, int);

	int NumOfVertices;
	ListNode **adjList;
	int *inDegree;
};

#endif
