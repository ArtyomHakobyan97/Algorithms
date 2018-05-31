#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
	int v1;
	int v2;
	int weight;
};

class Edge2 {
public:
	Edge2() = default;
	Edge2(int v2, int weight)
		: v2(v2)
		, weight(weight)
	{ }
	int v2;
	int weight;
};

// Adjacency list.
vector<vector<Edge2>> G;

// Adjacency matrix.
vector<vector<int>> G_matrix;

// List of edges.
vector<Edge> G_edges;

void read_graph() {
	int n, m; // n = |V|, m = |E|
	cin >> n >> m;
	G_matrix.resize(n);
	for (int i = 0; i < n; ++i) {
		G_matrix[i].resize(n);
	}
	G.resize(n);
	Edge current;
	for (int i = 0; i < m; ++i) {
		cin >> current.v1 >> current.v2 >> current.weight;
		// G_edges.push_back(current);
		// G_matrix[current.v1][current.v2] = current.weight;
		// G_matrix[current.v2][current.v1] = current.weight; // If graph was bidirectional/undirected.
		G[current.v1].push_back(Edge2(current.v2, current.weight));
		G[current.v2].push_back(Edge2(current.v1, current.weight)); // If graph was bidirectional/undirected.
	}
}

int main() {
	read_graph();
	return 0;
}
/*
|V| |E|
repeated |V| times
v1 v2 w

7 10
1 5 3
2 4 8
1 3 6
1 4 2
2 5 6
5 6 1
5 7 5
6 7 2
1 7 22
3 5 14

*/