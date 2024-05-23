/*
* 백준2473
* 이분탐색
* 20240520
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;
long long ans[3];
vector<long long> arr;
long long best_value = LLONG_MAX;

void TwoPointer(long long center)
{
	long long left = 0;
	long long right = arr.size() - 1;
	long long total = 0;
	
	while (left < center && right > center)
	{
		total = arr[left] + arr[center] + arr[right];
		if (total > 0)
		{
			if (abs(total) < abs(best_value))
			{
				best_value = total;
				ans[0] = arr[left];
				ans[1] = arr[center];
				ans[2] = arr[right];
			}
			right--;
		}
		else if (total < 0)
		{
			if (abs(total) < abs(best_value))
			{
				best_value = total;
				ans[0] = arr[left];
				ans[1] = arr[center];
				ans[2] = arr[right];
			}
			left++;
		}
		else
		{
			ans[0] = arr[left];
			ans[1] = arr[center];
			ans[2] = arr[right];
			break;
		}
	}
}

int main()
{
	long long N;
	cin >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < N - 1; i++)
	{
		TwoPointer(i);
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];

	return 0;
}