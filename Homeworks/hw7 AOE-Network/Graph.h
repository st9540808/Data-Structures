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
	vector<int> topologicalSort();
	void printEssential();
	void input(ifstream &); // construct the graph representation(adjacent list)
	void print();

private:
	void addNode(int, int, int);

	vector<ListNode *> adjList;
	vector<int> inDegree;
	vector<int> earlyTime;
	vector<int> lateTime;
};

#endif
