/*
* 백준11725 트리의 부모 찾기
* 트리
* 20240229
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<int> ans;
vector<bool> visited;

void DFS(int now) {
	if (visited[now]) return;

	for (int i : arr[now]) {
		if (!visited[i]) {

			visited[now] = true;
			ans[i] = now;
			DFS(i);
		}
	}
}

int main() {

	int N;
	cin >> N;

	arr.resize(N + 1);
	ans.resize(N + 1);
	visited.resize(N + 1);

	int u, v;
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}