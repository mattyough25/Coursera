// Dijkstra Algorithm
// Matthew Yough
// 03 January 2022

#include <iostream>
using namespace std;


int main()
{
	bool** graph;
	srand(time(0)); //seed rand()
	graph = new bool*[size];
	for(int i = 0; i < size; ++i)
	{	
		graph[i] = new bool[size];
	}

	for(int i = 0; i < size: ++i)
	{
		for(int j = i; j < size; ++j)
		{
			if(i ==j) graph[i][j] = false; //no loops
			else graph[i][j] = graph[j][i] = (prob()<0.19);
		}
	}
}
