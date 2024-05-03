/*
* 백준2468 안전 영역
* BFS
* 20240416
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, ans;

vector<vector<int>> arr;
vector<vector<bool>> visited;

void BFS(p start, int height) {
	queue<p> myQueue;
	myQueue.push(start);
	visited[start.first][start.second];
	ans++;

	while (!myQueue.empty()) {
		int cur_y = myQueue.front().first;
		int cur_x = myQueue.front().second;
		myQueue.pop();

		for (int i = 0; i < 4; i++) {
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];
			if (x >= 0 && x < N && y >= 0 && y < N) {
				if (!visited[y][x] && arr[y][x] > height) {
					visited[y][x] = true;
					myQueue.push(make_pair(y, x));
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		arr[i].resize(N);
		visited[i].resize(N);
	}

	int max_value = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			max_value = max(max_value, arr[i][j]);
		}
	}

	int max_ans = 0;
	for (int i = max_value; i >= 0; i--) {
		ans = 0;
		for (int i = 0; i < N; i++) {
			fill(visited[i].begin(), visited[i].end(), false);
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] && arr[j][k] > i) {
					BFS(make_pair(j, k), i);
				}
			}
		}
		max_ans = max(max_ans, ans);
	}

	cout << max_ans;

	return 0;
}