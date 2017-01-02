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
	Graph graph1;
	
	ifstream inputGraph("Sample_input.txt", ios::in);
	if (!inputGraph)
	{
		cerr << "File cannot be opened";
		exit(EXIT_FAILURE);
	}

	graph1.input(inputGraph);
	inputGraph.close();	

	return 0;
}
