/*
* 백준 2441 - 별 찍기 - 4
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j >= i) cout << "*";
			else cout << " ";
		}
		if (i != N - 1) cout << endl;
	}

	return 0;
}