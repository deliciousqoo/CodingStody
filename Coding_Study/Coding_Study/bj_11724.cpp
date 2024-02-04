#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;
void DFS(int now);
void dfs_stack(int now);

int main() {

	int N, M;
	cin >> N >> M;

	arr.resize(N + 1);
	visited.resize(N + 1, false);

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i < N+1; i++) {
		if (!visited[i]) {
			count++;
			DFS(i);
			//dfs_stack(i);
		}
	}

	cout << count;

	return 0;
}

void DFS(int now) {
	if (visited[now]) return;

	visited[now] = true;

	for (int i : arr[now]) {
		if (!visited[i]) DFS(i);
	}
}

void dfs_stack(int now) {

	stack<int> s;
	s.push(now);
	visited[now] = true;

	while (!s.empty()) {
		int top = s.top();
		s.pop();

		for (int i = 0; i < arr[top].size(); i++) {
			if (visited[arr[top][i]]) continue;
			s.push(arr[top][i]);
			visited[arr[top][i]] = true;
		}
	}
}