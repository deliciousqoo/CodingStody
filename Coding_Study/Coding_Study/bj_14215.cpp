/*
* ����14215 �� ����
* ����: ���簢���� �ﰢ��
* 20240226
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int A, B, C;
	cin >> A >> B >> C;

	if (A == 60 && B == 60 && C == 60) cout << "Equilateral" << "\n";
	else if (A + B + C == 180) {
		if (A != B && B != C && C != A) cout << "Scalene" << "\n";
		else cout << "Isosceles" << "\n";
	}
	else cout << "Error" << "\n";
}