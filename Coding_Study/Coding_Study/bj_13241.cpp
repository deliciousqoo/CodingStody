/*
* 백준13241 최소공배수
* 약수, 배수와 소수 2
* 20240326
*/
#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int A, B;
	cin >> A >> B;

	int temp = 1;
	while (true) {
		if (A * temp % B == 0) break;
		temp++;
	}

	cout << A * temp;

	return 0;
}