// Generates Random Graph
// 01/11/2022
// Matthew Yough

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

double prob()
{
	return (static_cast<double>(rand())/RAND_MAX);
}

int main()
{
	int size = 15; // default size
	double density;

	cout << "Enter Graph Size:" << endl;
	cin >> size;

	cout << "Enter Graph Density (Decimal from 0-1)" << endl;
	cin >> density;

	bool** graph;
	int** color;
	int** cost;

	srand(time(0)); // seed random number generator

	graph = new bool*[size];
	color = new int*[size];
	cost = new int*[size];

	for(int i = 0; i<size; ++i)
	{
		graph[i] = new bool[size];
		color[i] = new int[size];
		cost[i] = new int[size];
	}

	for(int i = 0; i < size; ++i) // generate undirected edges
	{
		for(int j = i; j<size; ++j)
		{
			if(i == j)
			{
				graph[i][j] = false; //no loops
			}
			else
			{
				graph[i][j] = graph[j][i] = (prob() < density);
			}
		}
	}

	for(int i = 0; i < size; ++i) // generate costs and colors
	{
		for(int j = i; j<size; ++j)
		{
			if(graph[i][j])
			{
				color[i][j] = color[j][i] = rand()%3;
				cost[i][j] = cost[j][i] = prob()*30;			
			}
		}
	}

	ofstream outp("graph_data.txt");
	outp << size << "\n";
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if(graph[i][j])
			{
				outp << i << '\t' << j << '\t' << cost[i][j] << '\t' << color[i][j] << '\t';
			}
		}
	}

}