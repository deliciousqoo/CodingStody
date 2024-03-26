/*
* 백준1735 분수 합
* 약수, 배수와 소수 2
* 20240326
*/
#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int A1, A2, B1, B2;
	cin >> A1 >> A2;
	cin >> B1 >> B2;

	A1 = A1 * B2 + B1 * A2;
	A2 = A2 * B2;
	
	int temp = 30000;
	while (temp > 1) {
		if (A1 % temp == 0 && A2 % temp == 0) {
			A1 /= temp;
			A2 /= temp;
		}
		else
		{
			temp--;
		}
	}

	cout << A1 << " " << A2;

	return 0;
}