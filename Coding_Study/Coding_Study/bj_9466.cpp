/*
* 백준 9466 - 텀 프로젝트
* 20240815
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> arr;
vector<bool> visited;
vector<bool> cycle_check;
int cnt = 0;

void DFS(int start)
{
	visited[start] = true;
	int next = arr[start];
	if (!visited[next])
	{
		DFS(next);
	}
	else if (!cycle_check[next])
	{
		for (int i = next; i != start; i = arr[i])
		{
			cnt++;
		}
		cnt++;
	}
	cycle_check[start] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		arr.resize(n + 1, 0);
		visited.resize(n + 1, false);
		cycle_check.resize(n + 1, false);
		cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i]) DFS(i);
		}

		cout << n - cnt << endl;

		arr.clear();
		visited.clear();
		cycle_check.clear();
	}

	return 0;
}