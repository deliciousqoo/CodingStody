/*
* ����19532 ������ ���鰭���Դϴ�
* �θ�Ʈ ����
* 20240228
*/
#include <iostream>

using namespace std;


int main() {

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	cout <<  (e * c - b * f) / (a * e - b * d) << " "<< (d * c - a * f) / (b * d - a * e);

	return 0;
}