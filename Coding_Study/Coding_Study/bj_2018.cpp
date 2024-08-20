/*
* 백준2018
* 투포인터
* 20240701
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int start = 1, end = 1, temp = 1, count = 0;
	while (start <= end)
	{
		if (temp < N)
		{
			end++;
			temp += end;
		}
		else if (temp > N)
		{
			temp -= start;
			start++;
		}
		else
		{
			count++;
			end++;
			temp += end;
		}
	}

	cout << count;
}