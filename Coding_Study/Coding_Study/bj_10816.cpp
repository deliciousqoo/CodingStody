/*
* 백준10816 숫자 카드 2
* 이분탐색
* 20240308
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

int Min_Search(int target, int start, int end) {
	int min_index = end;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] >= target) {
			min_index = mid;
			end = mid - 1;
		}
		else if (arr[mid] < target) {
			start = mid + 1;
		}
	}

	return min_index;
}

int Max_Search(int target, int start, int end) {
	int max_index = start;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] > target) {
			end = mid - 1;
		}
		else if (arr[mid] <= target) {
			max_index = mid;
			start = mid + 1;
		}
	}

	return max_index;
}

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
			int max = mid, min = mid;
			if (mid > start) {
				min = Min_Search(target, start, mid);
			}
			if (end > mid) {
				max = Max_Search(target, mid, end);
			}
			return max - min + 1;
		}
	}

	return 0;
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
		cout << Binary_Search(input, 0, arr.size() - 1) << " ";
	}

	return 0;
}