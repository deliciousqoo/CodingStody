/*
* 백준3273
* 투포인터
* 20240520
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x;
	cin >> n;

	vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> x;
	
	sort(arr.begin(), arr.end());

	int start = 0;
	int end = arr.size()-1;
	int sum = 0;
	int count = 0;

	while (end - start > 0)
	{
		sum = arr[start] + arr[end];
		if (sum < x)
		{
			start++;
		}
		else if (sum > x)
		{
			end--;
		}
		else
		{
			count++;
			start++;
			end--;
		}
	}

	cout << count;

	return 0;
}