/*
* 백준1967 트리의 지름
* 트리
* 20240301
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
vector<vector<p>> tree;

int BFS(vector<int> distance, vector<bool> visited, int now) {
	int max = -1;
	queue<int> myQueue;
	myQueue.push(now);
	visited[now] = true;
	
	while (!myQueue.empty()) {
		int temp = myQueue.front();
		myQueue.pop();

		for (p i : tree[temp]) {
			if (!visited[i.first]) {
				distance[i.first] = distance[temp] + i.second;
				if (distance[i.first] > max) max = distance[i.first];
				visited[i.first] = true;
				myQueue.push(i.first);
			}
		}
	}

	return max;
}

int main() {

	int n;
	cin >> n;

	vector<int> distance;
	vector<bool> visited;
	vector<bool> leaf_check;

	tree.resize(n + 1);
	visited.resize(n + 1, false);
	leaf_check.resize(n + 1, false);
	distance.resize(n + 1, 0);

	int u, v, w;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> w;
		tree[u].push_back(make_pair(v, w));
		tree[v].push_back(make_pair(u, w));
		leaf_check[u] = true;
	}

	int result;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (!leaf_check[i]) {
			result = BFS(distance, visited, i);
			if (result > max) max = result;
		}
	}

	cout << max;

	return 0;
}