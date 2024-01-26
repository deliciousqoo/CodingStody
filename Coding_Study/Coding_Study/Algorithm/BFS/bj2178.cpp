#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int maze[101][101];
static int N, M;
bool visited[101][101];

void BFS(int i, int j) {
	queue<pair<int, int>> myqueue;
	myqueue.push(make_pair(i, j));

	while (!myqueue.empty()) {
		int now[2];
		now[0] = myqueue.front().first;
		now[1] = myqueue.front().second;
		myqueue.pop();
		visited[i][j] = true;

		for (int k = 0; k < 4; k++) {
			int x = now[0] + dx[k];
			int y = now[1] + dy[k];

			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (!visited[x][y] && maze[x][y] != 0) {
					visited[x][y] = true;
					maze[x][y] = maze[now[0]][now[1]] + 1;
					myqueue.push(make_pair(x, y));
				}
			}
		}
	}
}


int main() {

	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < M; j++) {
			maze[i][j] = temp[j] - '0';
		}
	}
	BFS(0, 0);

	cout << maze[N-1][M-1];
	
	return 0;
}