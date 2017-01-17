/**
 * hw7 AOE Network
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Graph.h"

int main()
{
	std::ifstream inputGraph("Sample_input.txt", ios::in);
	if (!inputGraph)
	{
		std::cerr << "File cannot be opened";
		exit(EXIT_FAILURE);
	}

	Graph graph;
	graph.input(inputGraph);
	graph.topologicalSort();
	graph.printEssential();

	inputGraph.close();	
	return 0;
}
