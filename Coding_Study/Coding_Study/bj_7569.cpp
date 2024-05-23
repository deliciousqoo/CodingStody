/*
* น้มุ7569
* BFS
* 20240521
*/
#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> arr;
int dir[6][3] = { {1, 0, 0},{0, 1, 0},{-1, 0, 0},{0, -1, 0},{0, 0, 1},{0, 0, -1} };

int main()
{
	int M, N, H;
	cin >> M >> N >> H;
	arr.resize(H);
	for (int i = 0; i < H; i++)
	{
		arr[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			arr[i][j].resize(M);
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cout << arr[i][j][k] << " ";
			}
		}
	}
	



	return 0;
}