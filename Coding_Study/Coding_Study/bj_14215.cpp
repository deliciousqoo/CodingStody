/*
* 백준14215 세 막대
* 기하: 직사각형과 삼각형
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