/*
* 백준2110 공유기 설치
* 이분탐색
* 20240308
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int checkInstall(int distance) {

	int count = 1;

	int previous_install = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] - previous_install >= distance) {
			previous_install = arr[i];
			count++;
		}
	}

	return count;
}

int Binary_Search(int target) {
	int start = 1;
	int end = arr[arr.size() - 1] - arr[0];
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (checkInstall(mid) < target) {
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return end;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	cout << Binary_Search(C);

	return 0;
}