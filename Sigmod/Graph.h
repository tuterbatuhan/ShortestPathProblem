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
	std::set<uint32_t> getNeighbours(uint32_t v1,bool );
	void print();
	uint32_t getSize();
private:
	std::vector<std::set<uint32_t>> listIn, listOut;
};

