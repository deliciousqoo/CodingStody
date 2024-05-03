/*
* 백준7576 토마토
* BFS
* 20240416
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> p;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, ans;

vector<vector<int>> arr;

void BFS(p start) {
	queue<p> myQueue;
	myQueue.push(start);

	while (!myQueue.empty()) {
		int cur_y = myQueue.front().first;
		int cur_x = myQueue.front().second;
		myQueue.pop();

		for (int i = 0; i < 4; i++) {
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];
			if (x >= 0 && x < M && y >= 0 && y < N) {
				if (arr[y][x] != -1) {
					if (arr[y][x] == 0) {
						myQueue.push(make_pair(y, x));
						arr[y][x] = arr[cur_y][cur_x] + 1;
					}
					else
					{
						if (arr[y][x] > arr[cur_y][cur_x] + 1) {
							myQueue.push(make_pair(y, x));
							arr[y][x] = arr[cur_y][cur_x] + 1;
						}
					}
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++) {
		arr[i].resize(M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				BFS(make_pair(i, j));
			}
		}
	}
	
	int max_value = -1, check = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			max_value = max(max_value, arr[i][j]);
			if (arr[i][j] == 0) check = 1;
		}
	}

	if (check == 0) cout << max_value - 1;
	else if (check == 1) cout << -1;

	return 0;
}