/*
* 백준25304 영수증
* 반복문
* 20240220
*/
#include <iostream>

using namespace std;

int main() {

	int X, N, a, b;
	cin >> X;
	cin >> N;
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == X) cout << "Yes";
	else  cout << "No";

	return 0;
}