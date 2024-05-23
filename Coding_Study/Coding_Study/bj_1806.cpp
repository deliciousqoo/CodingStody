/*
* 백준1806
* 투포인터
* 20240519
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;

	int arr[100001] = { 0, };
	for (int i = 0; i < N; i++) cin >> arr[i];

	int start = 0, end = 0, min_length = 100001, total = arr[0];

	while (end < N)
	{
		if (total < S)
		{
			end++;
 			total += arr[end];
		}
		else if (total >= S)
		{
			min_length = min(min_length, end - start + 1);
			total -= arr[start];
			start++;
		}
	}

	if (min_length == 100001) cout << 0;
	else cout << min_length;

	return 0;
}