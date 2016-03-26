#include "QueryStructure.h"
#include <iostream>

using namespace std;
QueryStructure::QueryStructure()
{

}
QueryStructure::~QueryStructure()
{
}

Index QueryStructure::preprocess(Graph * G)
{
	Index L(G->getSize());
	P = new uint32_t[G->getSize()];
	for (size_t i = 0; i < G->getSize(); i++)
	{
		P[i] = 0;
	}
	for (size_t i = 0; i < G->getSize(); i++)//Graph Orders vertices itself according to their degrees
	{
		prunedBFS(G, i, &L);
	}
	return L;
}
void QueryStructure::prunedBFS(Graph * G, uint32_t vk, Index * L)
{
	queue <uint32_t> Q;
	Q.push(vk);
	while (!Q.empty())
	{
		uint32_t u = Q.front();
		//printf("\n: U:%u", u);
		Q.pop();
		if (L->query(vk, u, vk - 1)<=P[u])
			continue;
		L->addPairDistance(u, vk, P[u]);
		set<uint32_t> neighbours = G->getNeighbours(u);
		set<uint32_t>::iterator it = neighbours.begin();
		for (; it != neighbours.end(); it++)
		{
			if (P[*it] == 0 && *it != vk)
			{
				P[*it] = P[u] + 1;
				Q.push(*it);
				visited.push(*it);
			}
		}
	}
	while (!visited.empty())
	{
		P[visited.front()] = 0;
		visited.pop();
	}
	return;
}