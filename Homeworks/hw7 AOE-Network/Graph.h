#ifndef Graph_H
#define Graph_H

#include <fstream>
#include <string>
#include "ListNode.h"
using namespace std;

class Graph
{
public:
	Graph();
	~Graph();
	string topologicalSort();
	void input(ifstream &); //construct the graph representation(adjacent list)
	void print();

private:
	void addNode(int, int, int);

	int V; //number of vertices
	ListNode **adjList;
	int *inDegree;
};

#endif
