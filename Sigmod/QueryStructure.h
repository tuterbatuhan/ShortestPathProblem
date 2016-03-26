#pragma once
#include <stdint.h>
#include "Graph.h"
#include <map>
#include <queue>
#include "Index.h"
class QueryStructure
{
public:
	QueryStructure();
	~QueryStructure();
	Index preprocess(Graph * G);
private:
	void prunedBFS(Graph * G, uint32_t vertex,Index * index);
	uint32_t * P;
	queue<uint32_t> visited;
};

