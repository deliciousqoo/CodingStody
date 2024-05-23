/*
* 백준2512
* 이분탐색
* 20240520
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int Binary_Search(int target)
{
	int left = 0;
	int right = target;
	int mid;
	int ans = -1;

	while (left < right)
	{
		int total = 0, max_value = -1;
		mid = (left + right) / 2;
		for (int i = 0; i < arr.size(); i++)
		{
			total += min(mid, arr[i]);
			max_value = max(max_value, min(mid, arr[i]));
		}

		if (total <= target)
		{
			ans = max(max_value, ans);
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return ans;
}

int main()
{
	int N;
	cin >> N;
	
	arr.resize(N);

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		arr.push_back(input);
	}

	cin >> input;
	cout << Binary_Search(input);


	return 0;
}