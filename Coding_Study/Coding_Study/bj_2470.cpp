/*
* 백준2470
* 이분탐색
* 20240520
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

int main()
{
	int N;
	cin >> N;

	vector<int> arr;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int right = arr.size() - 1;
	int left = 0;
	int best_value = INT_MAX;
	p ans;

	int temp = 0;
	while (left < right)
	{
		temp = arr[left] + arr[right];
		if (abs(temp) < abs(best_value))
		{
			best_value = temp;
			ans = make_pair(arr[left], arr[right]);
		}
		if (temp < 0) left++;
		else if (temp > 0) right--;
		else
		{
			ans = make_pair(arr[left], arr[right]);
			break;
		}
	}

	cout << ans.first << " " << ans.second;

	return 0;
}