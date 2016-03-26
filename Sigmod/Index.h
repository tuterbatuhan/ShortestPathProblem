#pragma once
#include <stdint.h>
#include <vector>
#include <map>
using namespace std;
class Index
{
public:
	Index(uint32_t size);
	~Index();
	uint64_t query(uint32_t s, uint32_t t);
	uint64_t query(uint32_t s, uint32_t t, uint32_t k);
	void addPairDistance(uint32_t u, uint32_t vk ,uint32_t distance,bool);
	vector<map<uint32_t, uint32_t>> LIn, LOut;
	void print();
};

