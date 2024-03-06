/*
* 백준1920 수 찾기
* 이분탐색
* 20240306
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

void Binary_Search(int target) {
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] < target) {
			start = mid + 1;
		}
		else if (arr[mid] > target) {
			end = mid - 1;
		}
		else
		{
			cout << 1 << "\n";
			return;
		}
	}

	cout << 0 << "\n";
	return;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int input = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> input;
		Binary_Search(input);
	}

	return 0;
}