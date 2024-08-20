/*
* น้มุ
* 20240815
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, H;
typedef pair<int, pair<int, int>> p;
vector<vector<vector<int>>> arr;
queue<p> q;

int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};
int dz[6] = {-1, 1, 0, 0, 0, 0};

void BFS()
{
	while (!q.empty())
	{
		int cur_z = q.front().first;
		int cur_y = q.front().second.first;
		int cur_x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int z = cur_z + dz[i];
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];

			if (z >= 0 && z < H && y >= 0 && y < N && x >= 0 && x < M)
			{
				if (arr[z][y][x] == 0)
				{
					arr[z][y][x] = arr[cur_z][cur_y][cur_x] + 1;
					q.push(make_pair(z, make_pair(y, x)));
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

	cin >> M >> N >> H;

	arr.resize(H);
	for (int i = 0; i < H; i++)
	{
		arr[i].resize(N, vector<int>(M));
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) q.push(make_pair(i, make_pair(j, k)));
			}
		}
	}

	BFS();
	
	bool check = false;
	int ans = 0;
	for (int i = 0; i < H && !check; i++)
	{
		for (int j = 0; j < N && !check; j++)
		{
			for (int k = 0; k < M && !check; k++)
			{
				if (arr[i][j][k] == 0)
				{
					check = true;
					break;
				}
				
				ans = max(ans, arr[i][j][k]);
			}
		}
	}

	if (check) cout << -1;
	else cout << ans - 1;

	return 0;
}