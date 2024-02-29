/*
* 백준1018 체스판 다시 칠하기
* 부르트 포스
* 20240228
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(vector<vector<char>> arr, vector<vector<bool>> visited, edge start, int mode) {
	queue<edge> myQueue;
	myQueue.push(start);
	visited[start.first][start.second] = true;

	int count = 0;
	int min_x, min_y, max_x, max_y;
	if (mode == 0) {
		min_x = start.second;
		min_y = start.first;
		max_x = start.second + 8;
		max_y = start.first + 8;
	}
	else if (mode == 1) {
		min_x = start.second - 1;
		min_y = start.first;
		max_x = start.second + 7;
		max_y = start.first + 8;
	}
	else if (mode == 2) {
		min_x = start.second - 7;
		min_y = start.first;
		max_x = start.second + 1;
		max_y = start.first + 8;
	}

	while (!myQueue.empty()) {
		int cur_x = myQueue.front().second;
		int cur_y = myQueue.front().first;
		char cur_color = arr[cur_y][cur_x];
		myQueue.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur_x + dx[i];
			int y = cur_y + dy[i];

			

			if (x >= min_x && y >= min_y && x < max_x && y < max_y) {
				if (!visited[y][x]) {
					visited[y][x] = true;
					if (cur_color == 'W' && arr[y][x] == 'W') { arr[y][x] = 'B'; count++; }
					else if (cur_color == 'B' && arr[y][x] == 'B') { arr[y][x] = 'W'; count++; }
					myQueue.push(make_pair(y, x));
				}
			}
		}
	}

	return count;
}

int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<char>> chess;
	vector<vector<bool>> visited;

	chess.resize(N);
	visited.resize(N);
	for (int i = 0; i < chess.size(); i++) {
		chess[i].resize(M);
		visited[i].resize(M);
	}

	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			chess[i][j] = temp;
		}
	}

	int result;
	int min_value = 3000;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			result = min({ BFS(chess, visited, make_pair(i, j), 0), BFS(chess, visited, make_pair(i, j + 1), 1), BFS(chess, visited, make_pair(i, j + 7), 2)});
			if (result < min_value) min_value = result;
		}
	}

	cout << min_value;

	return 0;
}