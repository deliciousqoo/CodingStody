/*
* 백준2745 진법 변환
* 일반 수학
* 20240221
*/
#include <iostream>
#include <string>

using namespace std;

int main() {

	string N;
	int B;
	cin >> N >> B;

	long long int total = 0;
	for (int i = 0; i<N.length(); i++) {
		if (N[N.length() - 1 - i] < 'A') {
			total += (N[N.length() - 1 - i] - '0') * pow(B, i);
		}
		else
		{
			total += (N[N.length() - 1 - i] - 55) * pow(B, i);
		}
	}

	cout << total;

	return 0;
}