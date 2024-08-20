/*
* 백준 2445 - 별 찍기 - 8
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

	for (int i = 0; i < N * 2 - 1; i++)
	{
		for (int j = 0; j < N * 2; j++)
		{
			if (i <= (N * 2 - 1) / 2)
			{
				if (j <= i || j >= N * 2 - i - 1) cout << "*";
				else cout << " ";
			}
			else
			{
				if (j <= 2 * N - i - 2 || j > i) cout << "*";
				else cout << " ";
			}
		}

		if (i != N * 2 - 2) cout << endl;
	}

	return 0;
}