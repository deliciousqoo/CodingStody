/*
* 백준10813 공 바꾸기
* 1차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, M, i, j;
	cin >> N >> M;

	vector<int> arr(N + 1);
	for (int a = 1; a <= N; a++) {
		arr[a] = a;
	}

	for (int a = 0; a < M; a++) {
		cin >> i >> j;
		int temp;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	for (int a = 1; a <= N; a++) {
		cout << arr[a] << " ";
	}

	return 0;
}