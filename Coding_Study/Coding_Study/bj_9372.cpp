/*
* 백준9372
* 트리
* 20240521
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(1001);
bool visited[1001];
int parent[1001];

int main()
{
	
	int T, N, M, a, b;
	cin >> T;
	
	while (T-- > 0)
	{
		cin >> N >> M;
		
		for (int i = 1; i <= M; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
		}
		cout << N - 1 << '\n';
	}

	return 0;
}