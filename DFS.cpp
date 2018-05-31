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
bool found = false;
void dfs(int v) { // speed = O(|E|)
	marked[v] = true;
	if (v == G.size() - 1) { //  IF we're reached the last vertex.
		found = true;
		cout << v << ' ';
		return;
	}
	for (int i = 0; i < G[v].size(); ++i) { // < O(V)
		if (!marked[G[v][i].v2])
			dfs(G[v][i].v2);
		if (found) {
			cout << v << ' ';
			return;
		}
	}
	std::cout << " end of group" << std::endl;
	for (int i = 0; i < marked.size(); i++)
	{
		if (marked[i] == false)
		{
			dfs(i);
		}
	}
}

int main() {
	read_graph();
	marked.resize(G.size()); // size = |V|.
	for (int i = 0; i < G.size(); ++i)
		marked[i] = false;
	dfs(0); // dfs = depth first search
	return 0;
}
/*
|V| |E|
repeated |V| times
v1 v2 w

7 10 
0 4 3
1 3 8
0 2 6
0 3 2
1 4 6
4 5 1
4 6 5
5 6 2
0 6 22
2 4 14

*/