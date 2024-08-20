/*
* 백준11659
* 구간합
* 20240229
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	arr.resize(N+1);
	result.resize(N+1);
	for (int i = 0; i <= N; i++)
	{
		arr[i].resize(N+1, 0);
		result[i].resize(N+1, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			result[i][j] = arr[i][j] + result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << result[x2][y2] - result[x1-1][y2] - result[x2][y1-1] + result[x1-1][y1-1] << "\n";
	}

	return 0;
}