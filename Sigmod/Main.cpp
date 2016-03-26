#include <stdio.h>
#include "Graph.h"
#include <iostream>
#include "QueryStructure.h"
#include "Index.h"
using namespace std;
int main(int argc, const char* argv[])
{
	Graph G;
	G.addEdge(1, 2);
	G.addEdge(3, 2);
	G.addEdge(4, 3);
	G.addEdge(1, 3);
	G.addEdge(0, 1);
	
	//G.print();
	G.removeEdge(2, 3);
	//G.print(); 
	
	QueryStructure QS;
	Index L = QS.preprocess(&G);

	printf("Shortest Path: %u \n", L.query(0, 2));
	printf("Shortest Path: %u \n", L.query(4, 2));
	printf("Shortest Path: %u \n", L.query(2, 4));
	//L.print();
	system("pause");
}