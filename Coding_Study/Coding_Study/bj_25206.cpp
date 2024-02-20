/*
* 백준25206 너의 평점은
* 심화 1
* 20240220
*/
#include <iostream>

using namespace std;

int main() {

	string subject, grade;
	float credit, total_grade = 0, total_credit = 0;
	for (int i = 0; i < 20; i++) {
		cin >> subject >> credit >> grade;
		if (grade == "P") continue;

		total_credit += credit;
		if (grade == "A+") { total_grade += 4.5 * credit; }
		else if (grade == "A0") { total_grade += 4.0 * credit; }
		else if (grade == "B+") { total_grade += 3.5 * credit; }
		else if (grade == "B0") { total_grade += 3.0 * credit; }
		else if (grade == "C+") { total_grade += 2.5 * credit; }
		else if (grade == "C0") { total_grade += 2.0 * credit; }
		else if (grade == "D+") { total_grade += 1.5 * credit; }
		else if (grade == "D0") { total_grade += 1.0 * credit; }
		else if (grade == "F") { total_grade += 0.0 * credit; }
	}

	cout << total_grade / total_credit;
}