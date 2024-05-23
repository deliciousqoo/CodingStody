/*
* 백준1005
* 위상정렬
* 20240520
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int degree[32001];
vector<vector<int>> graph(32001);

void topology_sort()
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0) pq.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		int from = pq.top();
		pq.pop();
		cout << from << " ";
		for (int j = 0; j < graph[from].size(); j++)
		{
			int to = graph[from][j];
			degree[to]--;
			if (degree[to] == 0) pq.push(to);
		}
	}

	return;
}

int main()
{
	cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		degree[B]++;
	}

	topology_sort();

	return 0;
}