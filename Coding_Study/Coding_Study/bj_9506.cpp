/*
* 백준9506 약수들의 합
* 약수, 배수와 소수
* 20240226
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr;
	int n, total;

	while (true) {
		cin >> n;
		if (n == -1) break;

		arr.clear();
		total = 0;
		for (int i = 1; i <= n/2; i++) {
			if (n % i == 0) {
				arr.push_back(i);
				total += i;
			}
		}

		if (total == n) {
			cout << n << " = ";
			for (int i = 0; i < arr.size(); i++) {
				cout << arr[i];
				if (i != arr.size() - 1) {
					cout << " + ";
				}
			}
		}
		else
		{
			cout << n << " is NOT perfect.";
		}

		cout << "\n";
	}

	return 0;
}