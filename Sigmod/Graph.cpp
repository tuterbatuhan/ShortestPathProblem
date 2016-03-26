#include "Graph.h"

using namespace std;

Graph::Graph()
{
	
}
Graph::~Graph()
{
}
bool Graph::addEdge(uint32_t v1, uint32_t v2)
{
	if (listIn.size() <= (v1 > v2 ? v1 : v2))
	{
		listIn.resize((v1>v2 ? v1 : v2)+1);
		listOut.resize((v1>v2 ? v1 : v2) + 1);
	}
	listOut[v1].insert(v2);
	listIn[v2].insert(v1);
	return true;
}
bool Graph::removeEdge(uint32_t v1, uint32_t v2)
{
	listOut[v1].erase(v2);
	listIn[v2].erase(v1);
	return true;
}
void Graph::print()
{
	for (size_t i = 0; i < listIn.size(); i++)
	{
		printf("%d : ", i);
		std::set<uint32_t>::iterator it = listOut[i].begin();
		for (; it != listOut[i].end(); it++)
		{
			printf("%d ",*it);
		}
		printf("\n");
	}
}
std::set<uint32_t> Graph::getNeighbours(uint32_t v1,bool isIn)
{
	if (isIn == true)
		return listIn[v1];
	else
		return listOut[v1];
}
uint32_t Graph::getSize()
{
	return listIn.size();
}