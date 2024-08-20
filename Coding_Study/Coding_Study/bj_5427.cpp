/*
* น้มุ 5427
* 20240816
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
vector<vector<char>> maze;
vector<vector<bool>> visited;
queue<p> fires;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int R, C, cnt = 0;
bool check = false;

void fire_set()
{
	int size = fires.size();

	for (int i = 0; i < size; i++)
	{
		int cur_y = fires.front().first;
		int cur_x = fires.front().second;
		fires.pop();

		for (int j = 0; j < 4; j++)
		{
			int y = cur_y + dy[j];
			int x = cur_x + dx[j];

			if (y >= 0 && y < R && x >= 0 && x < C)
			{
				if (maze[y][x] == '.' || maze[y][x] == '@')
				{
					maze[y][x] = '*';
					fires.push(make_pair(y, x));
				}
			}
		}
	}
}

void BFS(p start)
{
	if (start.first == 0 || start.first == R - 1 || start.second == 0 || start.second == C - 1)
	{
		check = true;
		return;
	}

	queue<p> q;
	q.push(start);

	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		fire_set();
		int size = q.size();
		cnt++;

		for (int i = 0; i < size; i++)
		{
			int cur_y = q.front().first;
			int cur_x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int y = cur_y + dy[j];
				int x = cur_x + dx[j];

				if (y >= 0 && y < R && x >= 0 && x < C)
				{
					if (!visited[y][x] && maze[y][x] == '.')
					{
						visited[y][x] = true;
						q.push(make_pair(y, x));
						maze[y][x] = '@';
						if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
						{
							check = true;
							return;
						}
					}
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
		cin >> C >> R;

		maze.resize(R, vector<char>(C));
		visited.resize(R, vector<bool>(C, false));

		p start;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == '*') fires.push(make_pair(i, j));
				if (maze[i][j] == '@') start = make_pair(i, j);
			}
		}

		BFS(start);

		if (!check) cout << "IMPOSSIBLE\n";
		else cout << cnt + 1 << "\n";

		maze.clear();
		visited.clear();
		cnt = 0;
		check = false;
		while (!fires.empty()) fires.pop();
	}

	return 0;
}