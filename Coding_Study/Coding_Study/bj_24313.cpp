/*
* ����24313 �˰��� ���� - ������ ǥ�� 1
* �ð� ���⵵
* 20240227
*/
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	if (((a1 * n0) + a0 <= c * n0) && (a1 <= c)) cout << 1;
	else cout << 0;

	return 0;
}