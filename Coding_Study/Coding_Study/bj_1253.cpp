/*
* 백준1940
* 투포인터
* 20240701
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

bool TwoPointer(int target)
{
	int start = 0;
	int end = arr.size() - 1;
	int temp = 0;

	while (start < end)
	{
		if (start == target)
		{
			start++;
			continue;
		}
		if (end == target)
		{
			end--;
			continue;
		}

		temp = arr[start] + arr[end];
		if (temp > arr[target]) end--;
		else if (temp < arr[target]) start++;
		else return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	arr.resize(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (TwoPointer(i)) count++;
	}

	cout << count;

	return 0;
}