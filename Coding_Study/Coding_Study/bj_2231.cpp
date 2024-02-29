/*
* 백준2231 분해합
* 부르트 포스
* 20240228
*/
#include <iostream>
#include <string>

using namespace std;

int calculator(int num) {
	int total = 0;
	string temp = to_string(num);
	for (int i = 0; i < temp.size(); i++) {
		total += temp[i] - '0';
	}

	return num + total;
}

int main() {

	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i < N; i++) {
		if (N == calculator(i)) { ans = i; break; }
	}
	cout << ans;

	return 0;
}