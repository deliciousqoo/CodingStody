#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int now, int depth);

vector<vector<int>> arr;
vector<bool> visited;
static bool arrive;

int main() {

	int N, M;
	cin >> N >> M;

	arr.resize(N);
	visited.resize(N, false);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			DFS(i, 1);
			if (arrive) break;
		}
	}

	if (arrive) cout << "1";
	else cout << "0";

	return 0;
}

void DFS(int now, int depth) {
	if (depth == 5) {
		arrive = true;
		return;
	}

	visited[now] = true;

	for (int i : arr[now]) {
		if (!visited[i]) DFS(i, depth + 1);
	}
	visited[now] = false;
}