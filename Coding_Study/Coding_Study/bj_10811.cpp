/*
* 백준10811 바구니 뒤집기
* 1차원 배열
* 20240220
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M, i, j;
	cin >> N >> M;

	vector<int> arr(N + 1, 0);
	for (int a = 1; a <= N; a++) {
		arr[a] = a;
	}

	for (int a = 0; a < M; a++) {
		cin >> i >> j;
		reverse(arr.begin() + i, arr.begin() + j + 1);
	}
	
	for (int a = 1; a <= N; a++) {
		cout << arr[a] << " ";
	}

	return 0;
}