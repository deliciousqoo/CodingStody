/*
* 백준1940
* 투포인터
* 20240701
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int start = 0, end = arr.size() - 1, temp = arr[start] + arr[end], count = 0;
	while (start < end)
	{
		if (temp < M)
		{
			temp -= arr[start];
			start++;
			temp += arr[start];
		}
		else if (temp > M)
		{
			temp -= arr[end];
			end--;
			temp += arr[end];
		}
		else
		{
			count++;
			start++;
			end--;
			temp = arr[start] + arr[end];
		}
	}

	cout << count;

	return 0;
}