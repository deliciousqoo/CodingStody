/*
* 백준11726 2*n 타일링
* 동적계획법
* 20240311
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long long> D;

int main() {

	int n;
	cin >> n;

	D.resize(1001);
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= n; i++) {
		D[i] = (D[i - 1] + D[i - 2]) % 10007;
	}

	cout << D[n];

	return 0;
}