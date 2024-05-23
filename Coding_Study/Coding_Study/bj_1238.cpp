/*
* 백준1238 파티
* 다익스트라 알고리즘
* 20240521
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> mlist;
vector<int> mdistance;
priority_queue<edge, vector<edge>, greater<edge>> pq;

void dijkstra(int start)
{
	pq.push(make_pair(0, start));
	mdistance[start] = 0;

	while (!pq.empty())
	{
		edge current = pq.top();
		pq.pop();
		int cv = current.second;

		for (int i = 0; i < mlist[cv].size(); i++)
		{
			edge temp = mlist[cv][i];
			int next = temp.first;
			int value = temp.second;

			if (mdistance[next] > mdistance[cv] + value)
			{
				mdistance[next] = mdistance[cv] + value;
				pq.push(make_pair(mdistance[next], next));
			}
		}
	}
}

int main()
{
	int N, M, X;
	cin >> N >> M >> X;

	mlist.resize(N+1);
	mdistance.resize(N + 1, INT_MAX);

	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		mlist[u].push_back(make_pair(v, w));
	}

	int total_distance[1001] = { 0, };

	for (int i = 1; i <= N; i++)
	{
		dijkstra(i);
		total_distance[i] += mdistance[X];
		mdistance.clear();
		mdistance.resize(N + 1, INT_MAX);
	}

	dijkstra(X);

	int max_value = -1;
	for (int i = 1; i <= N; i++)
	{
		total_distance[i] += mdistance[i];
		max_value = max(max_value, total_distance[i]);
	}
	
	cout << max_value;

	return 0;
}