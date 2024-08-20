/*
* น้มุ
* 20240815
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> mdistance;
vector<bool> visited;

void make_graph()
{
	for (int i = 0; i <= 100000; i++)
	{
		if (i - 1 >= 0) graph[i].push_back(i - 1);
		if (i + 1 <= 100000) graph[i].push_back(i + 1);
		if (i * 2 <= 100000) graph[i].push_back(i * 2);
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];

			if (mdistance[next] > mdistance[cur] + 1)
			{
				mdistance[next] = mdistance[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	graph.resize(100001);
	mdistance.resize(100001, INT_MAX);
	visited.resize(100001, false);

	make_graph();

	mdistance[N] = 0;
	BFS(N);

	cout << mdistance[K];

	return 0;
}