/*
* 백준2720 세탁소 사장 동혁
* 일반 수학
* 20240221
*/
#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	int C_arr[4] = { 25, 10, 5, 1 };

	int C;
	int temp;
	for (int i = 0; i < T; i++) {
		cin >> C;
		for (int j : C_arr) {
			temp = C / j;
			C %= j;
			cout << temp << " ";
		}
		cout << "\n";
	}

	return 0;
}