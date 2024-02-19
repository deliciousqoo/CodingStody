/*
* 백준10989 수 정렬하기 3
* 정렬
* 20240219
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, temp;
	cin >> N;

	int arr[10001] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) cout << i << "\n";
		}
	}

	return 0;
}