/*
* 백준2003
* 투포인터
* 20240519
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int arr[10001];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = arr[0];
	int count = 0;
	while (end < N)
	{
		if (sum < M)
		{
			end++;
			sum += arr[end];
		}
		else if (sum > M)
		{
			sum -= arr[start];
			start++;
		}
		else
		{
			count++;
			end++;
			sum += arr[end];
		}
	}

	cout << count;

	return 0;
}