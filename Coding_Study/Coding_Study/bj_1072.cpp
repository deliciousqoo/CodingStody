/*
* 백준1072
* 이분탐색
* 20240520
*/
#include <iostream>
#include <math.h>

using namespace std;
long long X, Y;

int Binary_Search(int target)
{
	int left = 0;
	int right = 1000000000;
	int mid, temp;
	while (left < right)
	{
		mid = (left + right) / 2;
		temp = (Y + mid) * 100 / (X + mid);
		
		if (temp >= target)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}

	return left;
}

int main()
{
	cin >> X >> Y;
	long long Z = (Y * 100) / X;

	if (Z >= 99) cout << -1;
	else
	{
		cout << Binary_Search(Z + 1);
	}

	return 0;
}