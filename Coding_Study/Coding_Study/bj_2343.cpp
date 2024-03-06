/*
* ¹éÁØ2343 ±âÅ¸ ·¹½¼
* ÀÌºĞÅ½»ö
* 20240306
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int input;
	int start = -1, end = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input > start) start = input;
		end += input;

		arr.push_back(input);
	}

	int mid = 0, count = 0, sum = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		count = 0;
		sum = 0;

		for (int i = 0; i < N; i++) {
			if (sum + arr[i] > mid) {
				count++;
				sum = 0;
			}
			sum += arr[i];
		}
		if(sum != 0) count++;

		if (count <= M) {
			end = mid - 1;
		}
		else if (count > M) {
			start = mid + 1;
		}
	}

	cout << start;

	return 0;
}