/*
* ����9063 ����
* ����: ���簢���� �ﰢ��
* 20240226
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	int X, Y;
	int max_X = -10001, max_Y = -10001, min_X = 10001, min_Y = 10001;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		if (X > max_X) max_X = X;
		if (Y > max_Y) max_Y = Y;
		if (X < min_X) min_X = X;
		if (Y < min_Y) min_Y = Y;
	}

	cout << (max_X - min_X) * (max_Y - min_Y);
}