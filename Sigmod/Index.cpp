#include "Index.h"
#include <climits>

Index::Index(uint32_t size)
{
	LIn.resize(0);
	LIn.resize(size);
	LOut.resize(0);
	LOut.resize(size);
}
Index::~Index()
{
}
uint64_t Index::query(uint32_t s, uint32_t t, uint32_t k)
{
	uint64_t min = ULLONG_MAX;//Max Distance
	map<uint32_t, uint32_t>::iterator iS = LOut[s].begin();
	map<uint32_t, uint32_t>::iterator iT = LIn[t].begin();
	while (iS != LOut[s].end() && iT != LIn[t].end())
	{
		uint32_t v1 = iS->first;
		uint32_t v2 = iT->first;
		if (v1 > k || v2 > k)//Look only L(k-1)
			return min;
		uint64_t distance = iS->second+iT->second;
		if (v1 == v2 && distance < min)
		{
			min = distance;
			iS++;
			iT++;
		}
		else if (v1 < v2)
			iS++;
		else
			iT++;
	}
	return min;
}
void Index::addPairDistance(uint32_t u, uint32_t vk, uint32_t distance,bool isIn)
{
	if (isIn==false)
		LIn[u].insert(pair<uint32_t, uint32_t>(vk, distance));
	else
		LOut[u].insert(pair<uint32_t, uint32_t>(vk, distance));
}
uint64_t Index::query(uint32_t s, uint32_t t)
{
	return query(s, t, LIn.size());
}
void Index::print()
{
	for (size_t i = 0; i < LOut.size(); i++)
	{
		printf("%d : ", i);
		printf("Outs: ");
		std::map<uint32_t,uint32_t>::iterator it = LOut[i].begin();
		for (; it != LOut[i].end(); it++)
		{
			printf("(%u,%u) ", it->first,it->second );
		}
		printf("Ins: ");
		it = LIn[i].begin();
		for (; it != LIn[i].end(); it++)
		{
			printf("(%u,%u) ", it->first, it->second);
		}
		printf("\n");
	}
}