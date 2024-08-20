/*
* 백준 1926 - 그림
* 20240815
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int BFS(p start)
{
	int count = 1;

	visited[start.first][start.second] = true;

	queue<p> q;
	q.push(start);

	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = cur_x + dx[i];
			int y = cur_y + dy[i];

			if (x >= 0 && x < m && y >= 0 && y < n)
			{
				if (!visited[y][x] && arr[y][x] == 1)
				{
					q.push(make_pair(y, x));
					visited[y][x] = true;
					count++;
				}
			}
		}
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	arr.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int max_value = 0, count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && arr[i][j] == 1)
			{
				max_value = max(BFS(make_pair(i, j)), max_value);
				count++;
			}
		}
	}

	cout << count << endl << max_value;

	return 0;
}