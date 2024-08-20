/*
* 백준 2443 - 별 찍기 - 6
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

	for (int i = N; i > 0; i--)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << "*";
		}
		if (i != 1) cout << endl;
	}

	return 0;
}