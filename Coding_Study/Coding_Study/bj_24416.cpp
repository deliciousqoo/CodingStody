/*
* 백준24416 알고리즘 수업 - 피보나치 수 1
* 동적 계획법 1
* 20240326
*/
#include <iostream>

using namespace std;

int f[41];
int count1 = 0, count2 = 0;

int fib(int n) {
	if (n == 1 or n == 2) return 1;
	else {
		count1++;
		return fib(n - 1) + fib(n - 2);
	}
}

int fibonacci(int n) {
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		count2++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fib(n);
	fibonacci(n);
	
	count1++;
	cout << count1 << " " << count2;

	return 0;
}