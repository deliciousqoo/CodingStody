/*
* 백준10844 쉬운 계단 수
* 동적계획법
* 20240311
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<long long>> D;

int main() {

	int N;
	cin >> N;

	D.resize(101);
	for (int i = 1; i <= N; i++) {
		D[i].resize(10, 0);
	}
	for (int i = 1; i < 10; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) D[i][j] = D[i - 1][1];
			else if (j == 9) D[i][j] = D[i - 1][8];
			else
			{
				D[i][j] = D[i - 1][j - 1] % 1000000000 + D[i - 1][j + 1] % 1000000000;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += D[N][i];
	}

	cout << ans % 1000000000;

	return 0;
}