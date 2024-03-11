/*
* 백준1463 1로 만들기
* 동적계획법
* 20240311
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> D;

int main() {

	int N;
	cin >> N;

	D.resize(N + 1);
	D[1] = 0;

	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) { D[i] = min(D[i], D[i / 2] + 1); }
		if (i % 3 == 0) { D[i] = min(D[i], D[i / 3] + 1); }
	}

	cout << D[N];

	return 0;
}