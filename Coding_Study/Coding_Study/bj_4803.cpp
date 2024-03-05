/*
* 백준2263 트리의 순회
* 트리
* 20240305
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
bool check;

int node_count, edge_count;

void BFS(int now) {
	queue<int> myQueue;
	myQueue.push(now);
	visited[now] = true;
	node_count++;

	while (!myQueue.empty()) {
		int temp = myQueue.front();
		myQueue.pop();

		edge_count += tree[temp].size();
		for (int i : tree[temp]) {
			if (!visited[i]) {
				visited[i] = true;
				myQueue.push(i);
				node_count++;
			}
		}
	}
}

int main() {

	int n, m, index = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		tree.resize(n + 1);
		visited.resize(n + 1);

		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		int tree_count = 0;
		for (int i = 1; i <= n; i++) {
			node_count = 0;
			edge_count = 0;
			if (!visited[i]) {
				BFS(i);
				if (node_count - edge_count / 2 == 1) tree_count++;
			}
		}

		if (tree_count == 0) {
			printf("Case %d: No trees.\n", index);
		}
		else if (tree_count == 1) {
			printf("Case %d: There is one tree.\n", index);
		}
		else
		{
			printf("Case %d: A forest of %d trees.\n", index, tree_count);
		}

		index++;
		tree.clear();
		visited.clear();
	}

	return 0;
}