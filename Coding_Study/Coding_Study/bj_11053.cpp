/*
* 백준11053 가장 긴 증가하는 부분 수열
* 동적 계획법
* 20240326
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	int max_value = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		max_value = max(dp[i], max_value);
	}

	cout << max_value;

	return 0;
}