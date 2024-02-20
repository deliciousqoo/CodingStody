/*
* 백준10810 공 넣기
* 1차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, M, i, j, k;
	cin >> N >> M;
	
	vector<int> arr(N+1, 0);
	for (int a = 0; a < M; a++) {
		cin >> i >> j >> k;
		for (int b = i; b <= j; b++) {
			arr[b] = 0;
			arr[b] = k;
		}
	}

	for (int a = 1; a <= N; a++) {
		cout << arr[a] << " ";
	}

	return 0;
}