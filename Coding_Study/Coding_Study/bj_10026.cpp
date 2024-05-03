/*
* 백준10026 적록색약
* BFS
* 20240416
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, ans;

vector<vector<char>> arr;
vector<vector<bool>> visited;

void BFS(p start, char origin) {
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
				if (!visited[y][x] && arr[y][x] == origin) {
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) BFS(make_pair(i, j), arr[i][j]);
		}
	}
	cout << ans << " ";
	ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'R') arr[i][j] = 'G';
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) BFS(make_pair(i, j), arr[i][j]);
		}
	}
	cout << ans << " ";

	return 0;
}