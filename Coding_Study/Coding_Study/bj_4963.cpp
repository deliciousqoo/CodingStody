/*
* น้มุ4963
* BFS
* 20240416
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;
typedef pair<int, int> edge;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<vector<int>> map;

void BFS(edge start)
{
	queue<edge> myqueue;
	myqueue.push(start);
	map[start.first][start.second] = 0;

	while (!myqueue.empty())
	{
		edge current = myqueue.front();
		myqueue.pop();

		int cur_x = current.second;
		int cur_y = current.first;

		for (int i = 0; i < 8; i++)
		{
			int x = cur_x + dx[i];
			int y = cur_y + dy[i];
			if (x >= 0 && y >= 0 && x < w && y < h)
			{
				if (map[y][x] == 1)
				{
					map[y][x] = 0;
					myqueue.push(make_pair(y, x));
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

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		map.resize(h);
		for (int i = 0; i < h; i++)
		{
			map[i].resize(w);
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					BFS(make_pair(i, j));
					answer++;
				}
			}
		}

		cout << answer << '\n';
		map.clear();
	}

	return 0;
}