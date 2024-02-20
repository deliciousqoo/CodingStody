/*
* 백준2444 별 찍기 - 7
* 심화 1
* 20240220
*/
#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= (2*N)/2; i++) {
		for (int j = 1; j <= 2 * N - 1; j++) {
			if (j <= N - i) cout << " ";
			else if (j >= N + i) {
				cout << " "; break;
			}
			else cout << "*";
		}
		cout << endl;
	}
	for (int i = (2 * N) / 2 - 1; i > 0; i--) {
		for (int j = 1; j <= 2 * N - 1; j++) {
			if (j <= N - i) cout << " ";
			else if (j >= N + i) {
				cout << " "; break;
			}
			else cout << "*";
		}
		cout << endl;
	}

	return 0;
}