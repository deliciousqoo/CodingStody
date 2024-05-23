/*
* 백준12015 가장 긴 증가하는 부분 수열 2
* 동적계획법, 이분탐색
* 20240520
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_SIZE 1000001

vector<int> arr;
vector<int> dp;

int Binary_Search(int start, int end, int target) {

	int temp = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= target) {
			temp = mid;
		}
		else
		{
			start = mid + 1;
		}
	}

	return temp;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	arr.resize(MAX_SIZE);
	dp.resize(MAX_SIZE);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	int max_value = -1;
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], dp[Binary_Search(1, i-1, arr[i])] + 1);
		max_value = max(dp[i], max_value);
	}

	cout << max_value;

	return 0;
}*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
vector<int> ans;

int Binary_Search(int target)
{
	int left = 0;
	int right = ans.size()-1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (target <= ans[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	ans.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (ans[ans.size() - 1] < arr[i]) ans.push_back(arr[i]);
		else
		{
			ans[Binary_Search(arr[i])] = arr[i];
		}
	}

	cout << ans.size();

	return 0;
}