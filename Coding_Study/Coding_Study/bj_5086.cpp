/*
* 백준5086 배수와 약수
* 약수, 배수와 소수
* 20240226
*/
#include <iostream>

using namespace std;

int main() {

	int A, B;
	while (true) {
		cin >> A >> B;
		if (A == 0 && B == 0) break;

		if (A > B && A % B == 0) cout << "multiple" << "\n";
		else if (A < B && B % A == 0) cout << "factor" << "\n";
		else cout << "neither" << "\n";
	}

	return 0;
}