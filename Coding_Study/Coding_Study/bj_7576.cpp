/*
* 백준 7576 - 토마토
* 20240816
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
vector<vector<int>> arr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
queue<p> q;

void BFS()
{
	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];

			if (y >= 0 && y < N && x >= 0 && x < M)
			{
				if (arr[y][x] == 0)
				{
					arr[y][x] = arr[cur_y][cur_x] + 1;
					q.push(make_pair(y, x));
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

	cin >> M >> N;

	arr.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push(make_pair(i, j));
		}
	}

	BFS();

	int ans = -1;
	bool check = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				check = true;
				break;
			}
			ans = max(arr[i][j], ans);
		}
		if (check) break;
	}

	if (check) cout << -1;
	else cout << ans - 1;

	return 0;
}