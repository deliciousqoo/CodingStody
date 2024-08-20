/*
* 백준 2012 - 등수 매기기
* 20240816
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += abs(arr[i - 1] - i);
	}

	cout << sum;

	return 0;
}