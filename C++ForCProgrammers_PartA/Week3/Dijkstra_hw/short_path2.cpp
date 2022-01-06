// Shortest Path Algorithm
// 06 January 2022

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, double> E; // Edge is a pair of end vertex and cost

class Graph {
  private:
    int numV; // The number of vertices in the graph
    int numE; // The number of edges in the graph
    vector<E> * G; // The adjacent matrix of graph
  public:
    Graph(int size, double density, double dist_min,
        double dist_max); // ctor for Graph
    ~Graph(void); // dtor for Graph
    int size(void); // Getter for number of vertices in graph
    int numEdges(void); // Getter for number of edges in graph
    void averageShortestPath(int source); // get the average shortest path from source
    void addEdge(int source, int target, double cost); // adds an edge to the Graph
};

const double INF = numeric_limits<double>::infinity(); // infinite value

// returns a random double between 0 and 1 used as a probabilty
inline double prob(void) {
  random_device rd; // used as random seed
  static mt19937 rng; // create random generator
  rng.seed(rd()); // input the seed into the rng
  uniform_real_distribution<double> probability(0, 1); // create distribution
  return probability(rng); // return the random probability
}

// size: the number of vertices in the graph
// density: density of edges in the graph
// dist_min: mininum cost of an edge
// dist_max: maximum cost of an edge
Graph::Graph(int size, double density, double dist_min,
    double dist_max) : numV(size) {
  random_device rd; // used as a random seed
  mt19937 rng; // create random number generator
  rng.seed(rd()); // feed the seed into the rng
  uniform_real_distribution<double> randDist(dist_min, dist_max);

  G = new vector<E>[size]; // allocate memory for graph

  // populate the graph with edges according to the density
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(i != j && prob() < density) {
        double tempDist = randDist(rng); // random cost for the edge
        // undirected edge, so make edge both ways
        addEdge(i, j, tempDist);
      }
    }
  }
}

// source: the first vertex of the edge
// target: the second vertex of the edge
// cost: the distance of the edge
void Graph::addEdge(int source, int target, double cost) {
  G[source].push_back(make_pair(target, cost));
  G[target].push_back(make_pair(source, cost));
  numE++;
}

// deallocate the graph
Graph::~Graph(void) {
  vector<E>().swap(*G); // swap out with an empty vector, deallocating memory
}

// returns the number of vertices in the graph
int Graph::size(void) {
  return numV;
}

// returns the number of edges in the graph
int Graph::numEdges(void) {
  return numE;
}

// returns the average of the shortest path from the source vertex to every
// other vertex of the graph. Ignores vertices that are not connected to the
// source vertex
void Graph::averageShortestPath(int source) {
  // minHeap priority_queue for storing closed vertices
  priority_queue<E, vector<E>, greater<E>> minHeap;

  // stores distances of vertices from the source
  vector<double> dist(numV, INF);
  dist[source] = 0; // set source dist as 0 since it is itself
  minHeap.push({0, source}); // start with the source vertex

  while(!minHeap.empty()) {
    int nextV = minHeap.top().second; // get the vertex on top
    minHeap.pop(); // remove the top vertex
    for(auto &next : G[nextV]) { // loop through vertices connect to nextV
      int tempV = next.first; // the vertex connected
      double tempC = next.second; // the edge to the connected vertex

      if(dist[tempV] > dist[nextV] + tempC) {
        // found a shorter path => update the distance
        dist[tempV] = dist[nextV] + tempC;
        minHeap.push({dist[tempV], tempV});
      }
    }
  }

  // get the average by summing up the distances while excluding those that are
  // not connceted
  double avg = 0.0;
  int notConnected = 0;
  for(double d : dist) {
    if(d == INF) {
      notConnected++;
      continue;
    }
    avg += d;
  }
  cout << "# of vertices not connected to vertex " << source << " is: " << notConnected << endl;
  avg /= (numV - notConnected - 1);

  // report the avg shortest path
  cout << "Average shortest path from vertex " << source <<
    " is: " << avg << endl;
}

// The driver of this program, creates a new graph and calls the method that
// gets average shortest path from the first vertex.
int main(void) {

   int size = 0;
   double density, cost_min, cost_max;

   cout<<"Enter Graph Size"<<endl;
   cin >> size;

   cout<<"Enter Graph Density"<<endl;
   cin >> density;

   cout<<"Enter Minimum Cost from Vertex to Vertex"<<endl;
   cin >> cost_min;

   cout<<"Enter Maximum Cost from Vertex to Vertex"<<endl;
   cin >> cost_max;

  cout << "Output with " << density << " density:" << endl;
  Graph graph = Graph(size, density, cost_min, cost_max);
  cout << "size: " << graph.size() << "; edges: " << graph.numEdges() << endl;
  graph.averageShortestPath(0);

  system("pause");
}