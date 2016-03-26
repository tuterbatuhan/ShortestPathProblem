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
	if (list.size()<=(v1>v2 ? v1 : v2))
		list.resize((v1>v2 ? v1 : v2)+1);
	list[v1].insert(v2);
	list[v2].insert(v1);
	return true;
}
bool Graph::removeEdge(uint32_t v1, uint32_t v2)
{
	list[v1].erase(v2);
	return list[v2].erase(v1)==1;
}
void Graph::print()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		printf("%d : ", i);
		std::set<uint32_t>::iterator it = list[i].begin();
		for (; it != list[i].end(); it++)
		{
			printf("%d ",*it);
		}
		printf("\n");
	}
}