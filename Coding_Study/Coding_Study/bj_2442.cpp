/*
* 백준 2442 - 별 찍기 - 5
* 20240815
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << "*";
		}
		if (i != N) cout << endl;
	}

	return 0;
}