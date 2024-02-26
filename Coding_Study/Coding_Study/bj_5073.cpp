/*
* 백준5073 삼각형과 세 변
* 기하: 직사각형과 삼각형
* 20240226
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int A, B, C;
	vector<int> arr;

	while (true) {
		arr.clear();
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0) break;

		arr.push_back(A);
		arr.push_back(B);
		arr.push_back(C);

		sort(arr.begin(), arr.end(), greater<>());

		if (arr[0] < arr[1] + arr[2]) {
			if (A == B && B == C && C == A) cout << "Equilateral" << "\n";
			else if (A != B && B != C && C != A) cout << "Scalene" << "\n";
			else cout << "Isosceles" << "\n";
		}
		else
		{
			cout << "Invalid" << "\n";
		}
	}
}