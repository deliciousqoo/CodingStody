/*
* 백준12015 가장 긴 증가하는 부분 수열 2
* 동적계획법, 이분탐색
* 20240311
*/
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
		/*
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}*/
		dp[i] = max(dp[i], dp[Binary_Search(1, i-1, arr[i])] + 1);
		max_value = max(dp[i], max_value);
	}

	cout << max_value;

	return 0;
}