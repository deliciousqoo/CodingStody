/*
* 백준4803 트리
* 트리
* 20240303
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
bool check;

void DFS(int now) {
	if (visited[now]) return;
	visited[now] = true;

	for (int i : tree[now]) {
		if (!visited[i]) {
			DFS(i);
		}
		else
		{
			check = true;
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
		}

		int tree_count = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				check = false;
				DFS(i);
				if (check == true) tree_count--;
				else tree_count++;
			}
		}

		if (tree_count <= 0) {
			printf("Case %d: No trees.\n", index);
		}
		else if (tree_count == 1) {
			printf("Case %d: There is one tree.\n", index);
		}
		else
		{
			printf("Case %d: A forest of %d trees\n", index, tree_count);
		}

		tree.clear();
		visited.clear();
	}

	return 0;
}