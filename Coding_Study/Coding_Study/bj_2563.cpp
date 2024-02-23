/*
* 백준2563 색종이
* 2차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int arr[101][101] = { 0, };

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		for (int j = b; j < b + 10; j++) {
			for (int k = a; k < a + 10; k++) {
				arr[j][k] = 1;
			}
		}
	}

	int count = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] == 1) count++;
		}
	}

	cout << count;

	return 0;
}