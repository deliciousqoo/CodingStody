/*
* 백준2003
* 투포인터
* 20240519
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int arr[100001];
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (i < K) total += arr[i];
	}

	int temp_total = total;
	int start = 0;
	int end = start + K - 1;

	while (end < N - 1)
	{
		temp_total -= arr[start];
		start++;
		end++;
		temp_total += arr[end];
		total = max(temp_total, total);
	}

	cout << total;

	return 0;
}