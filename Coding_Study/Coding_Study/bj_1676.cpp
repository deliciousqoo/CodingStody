/*
* น้มุ
* 20240816
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int count2 = 0, count5 = 0, temp;
	do
	{
		if (N == 0) break;

		temp = N;
		while (temp % 2 == 0)
		{
			count2++;
			temp /= 2;
		}
		while (temp % 5 == 0)
		{
			count5++;
			temp /= 5;
		}
	} while (--N);

	cout << min(count2, count5);

	return 0;
}