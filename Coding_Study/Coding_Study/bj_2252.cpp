/*
* 백준2252
* 위상정렬
* 20240520
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int degree[32001];
vector<vector<int>> graph(32001);

void topology_sort()
{
	queue<int> q;
	
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (q.empty()) return;

		int from = q.front();
		cout << from << " ";
		q.pop();
		for (int j = 0; j < graph[from].size(); j++)
		{
			int temp = graph[from][j];
			degree[temp]--;
			if (degree[temp] == 0) q.push(temp);
		}
	}
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
