/*
* 백준10816 숫자 카드 2
* 이분탐색
* 20240307
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
int cnt = 0;


int Binary_Search(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		
		if (arr[mid] > target) {
			end = mid - 1;
		}
		else if (arr[mid] < target) {
			start = mid + 1;
		}
		else
		{
			if (mid > start) Min_Search(target, start, mid - 1);
			if (end > mid) Max_Search(target, mid + 1, end);
			return;
		}
	}
}

int Min_Search(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] > target) {
			end = mid - 1;
		}
		else if (arr[mid] < target) {
			start = mid + 1;
		}
		else
		{
			return;
		}
	}
}

int Max_Search(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] > target) {
			end = mid - 1;
		}
		else if (arr[mid] < target) {
			start = mid + 1;
		}
		else
		{
			return;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		cnt = 0;
		cout << Binary_Search(input) << " ";
	}

	return 0;
}