/*
* 백준2750 수 정렬하기
* 버블 정렬
* 20240207
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int temp;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}