/*
* 백준2193 이친수 구하기
* 동적계획법
* 20240311
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long long> D;

int main() {

	int N;
	cin >> N;

	D.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		if (i == 1) D[i] = 1;
		else if (i == 2) D[i] = 1;
		else D[i] = D[i - 1] + D[i - 2];
	}

	cout << D[N];

	return 0;
}