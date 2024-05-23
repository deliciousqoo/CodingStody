/*
* น้มุ1774
* MST
* 20240521
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator()(pair<double, int> p1, pair<double, int> p2)
	{
		if (p1.first > p2.first) return true;
		else return false;
	}
};

int N, M;
typedef pair<int, int> edge;
vector<vector<double>> graph;
priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;
bool visited[1001];

double distance(edge p1, edge p2)
{
	return sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2));
}

int main()
{
	cin >> N >> M;

	vector<edge> temp(N+1);
	int X, Y;
	for (int i = 1; i <= N; i++)
	{
		cin >> X >> Y;
		temp[i] = make_pair(X, Y);
	}

	graph.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		graph[i].resize(N + 1);
	}

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			graph[i][j] = distance(temp[i], temp[j]);
			graph[j][i] = distance(temp[j], temp[i]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		graph[X][Y] = 0;
		graph[Y][X] = 0;
	}

	visited[1] = true;
	for (int i = 2; i <= N; i++)
	{
		pq.push(make_pair(graph[1][i], i));
	}

	double answer = 0;
	while (!pq.empty())
	{
		int now = pq.top().second;
		double now_cost = pq.top().first;
		pq.pop();

		if (!visited)
		{
			visited[now] = true;
			answer += now_cost;
		}
		else continue;

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i]) pq.push(make_pair(graph[now][i], i));
		}
	}
	
	printf("%.2f", answer);

	return 0;
}
