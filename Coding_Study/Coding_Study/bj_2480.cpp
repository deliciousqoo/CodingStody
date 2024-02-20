/*
* 백준2480 주사위 세개
* 조건문
* 20240220
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int A, B, C, temp;
	cin >> A >> B >> C;
	
	if (A == B && B == C) {
		cout << 10000 + 1000 * A;
	}
	else if (A == B || B == C || A == C) {
		if (A == B) temp = A;
		else if (B == C) temp = B;
		else temp = C;
		cout << 1000 + 100 * temp;
	}
	else
	{
		temp = max({ A, B, C });
		cout << temp * 100;
	}

	return 0;
}