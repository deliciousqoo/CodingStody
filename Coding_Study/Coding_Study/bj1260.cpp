#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
vector<bool> visited;
vector<vector<int>> arr;

void DFS(int now) {
	if (visited[now]) return;

	visited[now] = true;

	for (int i : arr[now]) {
		if (!visited[i]) {
			cout << i << " ";
			DFS(i);
		}
	}
}

void BFS(int now) {
	queue<int> myqueue;
	myqueue.push(now);
	visited[now] = true;
	
	while (!myqueue.empty()) {
		int cur = myqueue.front();
		myqueue.pop();
		cout << cur << " ";
		for (int i : arr[cur]) {
			if (!visited[i]) {
				myqueue.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	
	int N, M, V;
	cin >> N >> M >> V;

	arr.resize(N + 1);
	visited.resize(N + 1, false);

	int input1, input2;
	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;
		arr[input1].push_back(input2);
		arr[input2].push_back(input1);
	}

	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	cout << V << " ";
	DFS(V);
	cout << endl;

	visited.clear();
	visited.resize(N + 1, false);

	BFS(V);

	return 0;
}