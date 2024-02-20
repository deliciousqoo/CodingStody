/*
* 백준11718 그대로 출력하기
* 문자열
* 20240220
*/
#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;
	for (int i = 0; i < 100; i++) {
		getline(cin, input);
		cout << input << endl;
	}

	return 0;
}