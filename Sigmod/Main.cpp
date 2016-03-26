#include <stdio.h>
#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include "QueryStructure.h"
#include "Index.h"
#include <climits>
using namespace std;
int main(int argc, const char* argv[])
{
	Graph G;
	QueryStructure QS;
	Index L(0);

	bool prep=true,dirty=true;
	for (std::string line; std::getline(std::cin, line);) 
	{
		if (prep)
		{
			if (line.at(0) != 'S')
			{
				stringstream stream(line);
				uint32_t v1, v2;
				stream >> v1;
				stream >> v2;
				G.addEdge(v1, v2);
			}
			else{
				L = QS.preprocess(&G);
				prep = false;
				cout << "R"<<endl;
			}
				
		}
		stringstream stream(line);
		uint32_t v1, v2;
		uint64_t dist;
		char c;
		stream >> c;
		switch (c)
		{
		case ('A') :
			stream >> v1;
			stream >> v2;
			G.addEdge(v1, v2);
			dirty = true;
			break;
		case ('D') :
			stream >> v1;
			stream >> v2;
			G.removeEdge(v1, v2);
			dirty = true;
			break;
		case ('Q') :
			stream >> v1;
			stream >> v2;
			if (dirty)
				L = QS.preprocess(&G);
			dirty = false;
			dist = L.query(v1, v2);
			if (dist!=ULLONG_MAX)
				cout <<dist<<"\n";
			else
				cout << -1 << "\n";
			break;
		default:
			break;
		}
	}
	system("pause");
}