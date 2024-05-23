/*
* น้มุ1197
* MST
* 20240520
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> edge;
int V, E;
int parents[10001];
vector<edge> graph;

bool cmp(edge e1, edge e2)
{
	if (e1.second < e2.second) return true;
	else return false;
}

int getParent(int x)
{
	if (parents[x] == x) return x;
	return parents[x] = getParent(parents[x]);
}

void unionParent(int index)
{
	int par_a = getParent(graph[index].first.first);
	int par_b = getParent(graph[index].first.second);
	if (par_a < par_b) parents[par_b] = par_a;
	else parents[par_a] = par_b;
}

bool find(int index)
{
	int par_a = getParent(graph[index].first.first);
	int par_b = getParent(graph[index].first.second);
	if (par_a == par_b) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		parents[i] = i;
	}

	edge temp;
	int A, B, C;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		graph.push_back(make_pair(make_pair(A, B), C));
	}

	sort(graph.begin(), graph.end(), cmp);

	int answer = 0;
	for (int i = 0; i < E; i++)
	{
		if (!find(i))
		{
			unionParent(i);
			answer += graph[i].second;
		}
	}

	cout << answer;

	return 0;
}