/*
* 백준1253
* 이분탐색
* 20240520
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

bool TwoPointer(int target)
{
	int left = 0;
	int right = arr.size() - 1;
	int temp = 0;
	while (left < right)
	{
		if (left == target)
		{
			left++;
			continue;
		}
		if (right == target)
		{
			right--;
			continue;
		}

		temp = arr[left] + arr[right];
		if (temp > arr[target]) right--;
		else if (temp < arr[target]) left++;
		else return true;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;
	
	arr.resize(N);

	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr.begin(), arr.end());

	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (TwoPointer(i)) count++;
	}

	cout << count;

	return 0;
}