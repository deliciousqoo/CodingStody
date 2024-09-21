#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>

using namespace std;

int M, N;
map<int, vector<int>> wormHoles;
map<int, bool> visited;

int BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	int cnt = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < wormHoles[cur].size(); i++)
		{
			if (!visited[wormHoles[cur][i]])
			{
				q.push(wormHoles[cur][i]);
				visited[wormHoles[cur][i]] = true;
			}
		}
	}

	if (cnt > N) return 0;
	else return cnt;
}

int main()
{
	cin >> M >> N;

	int ans = 0;
	vector<int> IDs;

	int ID1, ID2;
	for (int i = 0; i < M; i++)
	{
		cin >> ID1 >> ID2;
		wormHoles[ID1].push_back(ID2);
		wormHoles[ID2].push_back(ID1);
		IDs.push_back(ID1);
		IDs.push_back(ID2);
		visited[ID1] = false;
		visited[ID2] = false;
	}

	for (int i = 0; i < IDs.size(); i++)
	{
		if (!visited[IDs[i]])
		{
			ans += BFS(IDs[i]);
		}
	}

	cout << ans;

	return 0;
}