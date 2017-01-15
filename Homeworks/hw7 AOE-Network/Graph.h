/**
 *	Graph Definition
 */

#ifndef Graph_H
#define Graph_H

#include <fstream>
#include <vector>
#include "ListNode.h"
using namespace std;

class Graph
{
public:
	Graph();
	~Graph();
	bool isDAG();
	vector<int> topologicalSort();
	void input(ifstream &); //construct the graph representation(adjacent list)
	void print();

private:
	void addNode(int, int, int);

	vector<ListNode *>::size_type V; //number of vertices
	vector<ListNode *> adjList;
	vector<int> inDegree;
};

#endif
