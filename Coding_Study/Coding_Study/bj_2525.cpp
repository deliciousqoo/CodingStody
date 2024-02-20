/*
* 백준2525 오븐 시계
* 조건문
* 20240220
*/
#include <iostream>

using namespace std;

int main() {

	int A, B, C;
	cin >> A >> B;
	cin >> C;

	int temp;

	B += C;
	if (B >= 60) {
		temp = B / 60;
		B %= 60;
		A += temp;
		if (A >= 24) {
			A -= 24;
		}
	}
	
	cout << A << " " << B;

	return 0;
}