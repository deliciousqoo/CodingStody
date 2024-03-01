/*
* 백준1068 트리
* 트리
* 20240229
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;
int ans = 0;

void DFS(int now) {
	if (visited[now]) return;
	visited[now] = true;

	bool check = false;
	for (int i : arr[now]) {
		if (!visited[i]) {
			DFS(i);
			check = true;
		}
	}
	if (!check) ans++;
}

int main() {

	int N;
	cin >> N;

	arr.resize(N);
	visited.resize(N);

	int input, root;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == -1) root = i;
		else arr[input].push_back(i);
	}

	int cut;
	cin >> cut;
	visited[cut] = true;

	DFS(root);
	
	cout << ans;

	return 0;
}