/*
* 백준9086 문자열
* 문자열
* 20240220
*/
#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	string input;
	for (int i = 0; i < T; i++) {
		cin >> input;
		cout << input[0] << input[input.length() - 1] << endl;
	}

	return 0;
}