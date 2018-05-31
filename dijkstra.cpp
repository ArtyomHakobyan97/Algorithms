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
	Edge current;
	G.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> current.v1 >> current.v2 >> current.weight;
		// G_edges.push_back(current);
		// G_matrix[current.v1][current.v2] = current.weight;
		// G_matrix[current.v2][current.v1] = current.weight; // If graph was bidirectional/undirected.
		G[current.v1].push_back(Edge2(current.v2, current.weight));
		G[current.v2].push_back(Edge2(current.v1, current.weight)); // If graph was bidirectional/undirected.
	}
}
vector<bool> marked;
vector<int> d;

void print_d() {
	for (int i = 0; i < G.size(); ++i) {
		if (d[i] == INT_MAX / 2) {
			cout << "- ";
		}
		else {
			cout << d[i] << " ";
		}
	}
	cout << endl;
}

void dijkstra(int v) {
	marked.resize(G.size()); // size = |V|.
	for (int i = 0; i < G.size(); ++i)
		marked[i] = false;
	d.resize(G.size()); // size = |V|.
	for (int i = 0; i < G.size(); ++i)
		d[i] = INT_MAX / 2;
	d[v] = 0;
	for (int i = 0; i < G.size(); ++i) { // O(V)
		int min = INT_MAX;
		int argmin;
		for (int j = 0; j < G.size(); ++j) { // O(V)
			if (!marked[j] && d[j] < min) {
				min = d[j];
				argmin = j;
			}
		}
		// iterate over the neighbours of "argmin".
		for (int j = 0; j < G[argmin].size(); ++j) { // O(E/V) in average.
			if (d[G[argmin][j].v2] > d[argmin] + G[argmin][j].weight) {
				d[G[argmin][j].v2] = d[argmin] + G[argmin][j].weight;
			}
		}
		marked[argmin] = true;
		print_d();
	}
	
}

int main() {
	read_graph();
	dijkstra(0);
	return 0;
}
/*
|V| |E|
repeated |V| times
v1 v2 w

8 16 
0 1 1
0 2 5
0 3 4
1 2 3
1 3 2
1 4 5
1 5 10
2 3 3 
3 4 2
3 6 6
3 7 9
4 5 1
4 6 4
5 6 2
5 7 7
6 7 2

*/