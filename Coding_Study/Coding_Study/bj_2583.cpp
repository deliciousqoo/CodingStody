/*
* น้มุ
* 20240816
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
typedef pair<int, int> p;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(p start)
{
	int size = 1;

	queue<p> q;
	q.push(start);

	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];

			if (x >= 0 && x < N && y >= 0 && y < M)
			{
				if (!visited[y][x] && arr[y][x] == 0)
				{
					size++;
					visited[y][x] = true;
					q.push(make_pair(y, x));
				}
			}
		}
	}

	return size;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	arr.resize(M, vector<int>(N, 0));
	visited.resize(M, vector<bool>(N, false));
	
	int sx, sy, ex, ey;
	for (int i = 0; i < K; i++)
	{
		cin >> sx >> sy >> ex >> ey;
		for (int j = sy; j < ey; j++)
		{
			for (int k = sx; k < ex; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	int area_count = 0;
	vector<int> area_sizes;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && arr[i][j] == 0)
			{
				area_sizes.push_back(BFS(make_pair(i, j)));
				area_count++;
			}
		}
	}

	sort(area_sizes.begin(), area_sizes.end());

	cout << area_count << "\n";
	for(int i=0;i<area_sizes.size();i++)	
	{
		cout << area_sizes[i] << " ";
	}

	return 0;
}