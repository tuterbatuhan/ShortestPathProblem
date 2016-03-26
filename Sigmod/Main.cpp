#include <stdio.h>
#include "Graph.h"
using namespace std;
#include <iostream>
int main(int argc, const char* argv[])
{
	Graph G;
	G.addEdge(1, 2);
	G.addEdge(3, 2);
	G.addEdge(4, 3);
	G.addEdge(1, 3);
	G.addEdge(0, 1);
	G.print();

	system("pause");
}