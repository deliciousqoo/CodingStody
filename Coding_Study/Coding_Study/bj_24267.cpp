/*
* 백준24267 알고리즘 수업 - 알고리즘의 수행 시간 6
* 시간 복잡도
* 20240227
*/
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	long long n;
	cin >> n;

	cout << n * (n-1) * (n-2) / 6 << endl << 3;

	return 0;
}