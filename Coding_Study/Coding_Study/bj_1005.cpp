/*
* 백준1005
* 위상정렬
* 20240520
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, total_time;
int degree[1001];
vector<vector<int>> graph;
int build_time[1001];
int dp[1001];

void topology_sort(int target)
{
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0) q.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		if (q.empty()) return;

		int from = q.front();
		q.pop();
		for (int j = 0; j < graph[from].size(); j++)
		{
			int to = graph[from][j];
			degree[to]--;
			if (degree[to] == 0) q.push(to);
			dp[to] = max(dp[to], build_time[to] + dp[from]);
		}
	}
}

int main()
{
	int T, X, Y, W;
	cin >> T;

	while (T-- > 0)
	{
		cin >> N >> K;
		graph.resize(1001);

		for (int i = 1; i <= N; i++)
		{
			cin >> build_time[i];
			dp[i] = build_time[i];
		}

		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			graph[X].push_back(Y);
			degree[Y]++;
		}

		cin >> W;
		topology_sort(W);

 		cout << dp[W] << '\n';
		fill(dp, dp + 1001, 0);
		fill(degree, degree + 1001, 0);
		fill(build_time, build_time + 1001, 0);
		graph.clear();
	}

	return 0;
}