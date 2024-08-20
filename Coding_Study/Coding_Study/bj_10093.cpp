/*
* 백준 10093 - 숫자
* 20240815
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	long long a = min(A, B);
	long long b = max(A, B);

	int temp = b - a - 1;
	if (temp < 0) cout << 0 << endl;
	else cout << temp << endl;

	for (long long i = a + 1; i < b; i++)
	{
		cout << i << " ";
	}

	return 0;
}