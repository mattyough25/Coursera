// Kruskal Minimum Spanning Tree
// 13 January 2022

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Create a pair to store edges
typedef pair<int, int> edge;

// Graph class
class Graph{
    int V;
public:
    vector<pair<int,edge>> adjList;

    // Graph constructor
    Graph(int vertices)
    {
        V = vertices;
    }

    // Edge constructor for undirected graph
    void addEdge(int src, int target, int weight)
    {
        adjList.push_back(make_pair(weight,edge(src,target)));
        adjList.push_back(make_pair(weight,edge(target,src)));
    }
};

// Find the connection between nodes
int find(int parent[], int i)  
{  
    // If there is a connection, return node
    if (parent[i] == i)  
        return i;  
   
    return find(parent, parent[i]);  
}  

// Connect Nodes
void Union(int parent[],int u, int v) 
{
    parent[u] = parent[v];
}

// Function of Kruskal's algorithm
void kruskal(Graph &graph) 
{
    int i, uRep, vRep;

    // Size of the graph edges
    int S = graph.adjList.size();

    // Sort the edges according to weights
    std::sort(graph.adjList.begin(), graph.adjList.end()); 

    // Define vector Tree to store MST
    // Define parent array to store representative nodes
    vector<pair<int,edge>> Tree;
    int* parent;
    parent = new int[S];

    // Initialize parent array, each subset contains only single element
    for (int v = 0; v < S; v++)
        parent[v] = v;
    
    // Loop through all edges in graph
    for (i = 0; i < S; i++) 
    {
        // Use union-find algorithm to detect cycles
        // Find connection between two nodes in the edge
        uRep = find(parent, graph.adjList[i].second.first);
        vRep = find(parent, graph.adjList[i].second.second);

        if (uRep != vRep)
        {
            Tree.push_back(graph.adjList[i]); 
            Union(parent, uRep, vRep);
        }
    }

    // Print the tree and calculate the MST
    int sum = 0;
    cout << "Edges of the Minimum Spanning Tree: " << endl;
    for (int j = 0; j < Tree.size(); j++)
    {
        cout << "From Node " << Tree[j].second.first << " to Node " << Tree[j].second.second << 
        " the length is " << Tree[j].first << endl;
        sum += Tree[j].first;
    }
    // MST
    cout << "Minimum Spanning Tree length: " << sum << endl;
}


int main() 
{
    // Read the input file and set the number of vertices
    string sLine;
    ifstream infile;
    infile.open("sample_test_data.txt");

    // Read the first line for the number of vertices
    int N;
    getline(infile, sLine);
    N = stoi(sLine);

    // Create the graph
    Graph g(N);

    // Read the rest of the line to set the edges
    int i, j, cost;
    while(infile >> i >> j >> cost)
    {
        g.addEdge(i, j, cost);
    }

    // Kruskal algorithm
    kruskal(g);
	return 0;
}