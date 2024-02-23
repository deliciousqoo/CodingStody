/*
* 백준11005 진법 변환 2
* 일반 수학
* 20240221
*/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {

	long long int N;
	int B;
	cin >> N >> B;

	int pow_num = 0;
	while (true) {
		if (pow(B, pow_num) > N) {
			pow_num--;
			break;
		}
		pow_num++;
	}
	
	long long int temp;
	while (pow_num >= 0) {
		temp = N / pow(B, pow_num);

		if (temp < 10) printf("%c", temp + '0');
		else printf("%c", temp + 55);

		N -= pow(B, pow_num) * temp;

		pow_num--;
	}

	return 0;
}