/*
* 백준 1267 - 핸드폰 요금
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

	int input, Y = 0, M = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		Y += 10 * (input / 30 + 1);
		M += 15 * (input / 60 + 1);
	}

	if (Y == M) cout << "Y M " << Y;
	else
	{
		if (Y < M)
		{
			cout << "Y " << Y;
		}
		else
		{
			cout << "M " << M;
		}
	}

	return 0;
}