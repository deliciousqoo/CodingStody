/*
* 백준19532 수학은 비대면강의입니다
* 부르트 포스
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