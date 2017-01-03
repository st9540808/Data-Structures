/**
 * hw7 AOE Network
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Graph.h"
using namespace std;

int main()
{
	Graph graph;
	
	ifstream inputGraph("Sample_input.txt", ios::in);
	if (!inputGraph)
	{
		cerr << "File cannot be opened";
		exit(EXIT_FAILURE);
	}

	graph.input(inputGraph);
	graph.print();

	inputGraph.close();	

	return 0;
}

