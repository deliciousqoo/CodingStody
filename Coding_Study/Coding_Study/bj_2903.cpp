/*
* ����2903 �߾� �̵� �˰���
* �Ϲ� ����
* 20240226
*/
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int N;
	cin >> N;

	int temp = 2;
	long long int ans;
	for (int i = 0; i < N; i++) {
		temp = (temp * 2) - 1;
	}
	ans = pow(temp, 2);
	cout << ans;

	return 0;
}