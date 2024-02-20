/*
* 백준10988 팰린드롬인지 확인하기
* 심화 1
* 20240220
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	string input;
	cin >> input;

	string temp = input;
	reverse(temp.begin(), temp.end());

	if (input == temp) cout << 1;
	else cout << 0;

	return 0;
}