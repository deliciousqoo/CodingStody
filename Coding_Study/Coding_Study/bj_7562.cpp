/*
* 백준7562 - 나이트의 이동
* 20240817
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> p;
vector<vector<int>> chess;
vector<vector<bool>> visited;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int N, sY, sX, tY, tX;;

void BFS(p start)
{
	queue<p> q;
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];

			if (y >= 0 && y < N && x >= 0 && x < N)
			{
				if (!visited[y][x])
				{
					visited[y][x] = true;
					chess[y][x] = chess[cur_y][cur_x] + 1;
					q.push(make_pair(y, x));

					if (y == tY && x == tX) return;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> N;

		chess.resize(N, vector<int>(N, INT_MAX));
		visited.resize(N, vector<bool>(N));

		cin >> sY >> sX >> tY >> tX;

		chess[sY][sX] = 0;
		BFS(make_pair(sY, sX));

		cout << chess[tY][tX] << "\n";

		chess.clear();
		visited.clear();
	}

	return 0;
}