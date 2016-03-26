#pragma once
#include <stdint.h>
#include <vector>
#include <set>
class Graph
{
public:
	Graph();
	~Graph();
	bool addEdge(uint32_t v1, uint32_t v2);
	bool removeEdge(uint32_t v1, uint32_t v2);
	void print();
private:
	std::vector<std::set<uint32_t>> list;
};

