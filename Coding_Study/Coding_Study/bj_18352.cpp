/*
* 백준18352
* 다익스트라 알고리즘
* 20240521
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int N, M, K, X;
typedef pair<int, int> edge;
vector<vector<edge>> mlist;
vector<bool> visited;
vector<int> mdistance;
priority_queue<edge, vector<edge>, greater<edge>> pq;

void Dijkstra(int start)
{
	pq.push(make_pair(0, start));
	mdistance[start] = 0;

	while (!pq.empty())
	{
		edge current = pq.top();
		pq.pop();
		int cv = current.second;

		if (visited[cv]) continue;
		visited[cv] = true;

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
	cin >> N >> M >> K >> X;

	mlist.resize(N + 1);
	visited.resize(N + 1, false);
	mdistance.resize(N + 1, INT_MAX);

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		mlist[A].push_back(make_pair(B, 1));
	}

	Dijkstra(X);

	int count = 0;
	vector<int> ans;
	for (int i = 1; i <= mdistance.size()-1; i++)
	{
		if (mdistance[i] == K) ans.push_back(i);
	}

	if (ans.size() == 0) cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}

	return 0;
}