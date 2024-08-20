/*
* น้มุ
* 20240816
*/
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
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
		int M, N, x, y, ans = -1;
		cin >> M >> N >> x >> y;
		int maxi = lcm(M, N);
		for (int i = x; i <= maxi; i += M)
		{
			int temp_y = i % N;
			if (temp_y == 0) temp_y = N;
			if (temp_y == y)
			{
				ans = i;
				break;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}