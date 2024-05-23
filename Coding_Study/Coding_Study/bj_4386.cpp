/*
* น้มุ4386
* MST
* 20240521
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

float distance(edge p1, edge p2)
{
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main()
{
	int n;
	cin >> n;

	float x, y;
	vector<edge> temp;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		temp.push_back(make_pair(x, y));
	}

	vector<vector<float>> graph(n, vector<float>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			graph[i][j] = distance(temp[i], temp[j]);
			graph[j][i] = distance(temp[j], temp[i]);
		}
	}

	vector<int> visited;
	vector<int> unvisited;

	visited.push_back(0);
	for (int i = 1; i < n; i++) unvisited.push_back(i);
	
	float answer = 0;
	for (int i = 1; i < n; i++)
	{
		float min = INT_MAX;
		int min_index = 0;

		for (int j = 0; j < visited.size(); j++)
		{
			for (int k = 0; k < unvisited.size(); k++)
			{
				if (graph[visited[j]][unvisited[k]] > 0 && graph[visited[j]][unvisited[k]] < min)
				{
					min = graph[visited[j]][unvisited[k]];
					min_index = k;
				}
			}
		}

		visited.push_back(unvisited[min_index]);
		unvisited.erase(unvisited.begin() + min_index);
		answer += min;
	}

	printf("%.2f", answer);

	return 0;
}