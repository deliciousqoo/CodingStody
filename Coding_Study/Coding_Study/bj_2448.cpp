/*
* 백준 2448 - 별 찍기 - 11
* 20240816
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> arr;
int N;

void settings()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < arr[i].size() - i; j++)
		{
			arr[N-i-1][j] = '*';
		}
	}
}

void set_empty(int size)
{
	int count = 0;
	for (int i = size / 2; i < size; i++)
	{
		for (int j = i; j < i+size-1 - count; j++)
		{
			arr[i][j] = ' ';
		}
		count += 2;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(2 * (N - 1) + 1, ' ');
	}

	settings();

	set_empty(N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}