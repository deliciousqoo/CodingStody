#include <iostream>
#include <vector>

using namespace std;
static int N;
void DFS(int now, int jaritsu);
bool isPrime(int number);

int main() {
	/*
	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
	*/

	

	return 0;
}


void DFS(int now, int jaritsu) {
	if (jaritsu == N) {
		if (isPrime(now)) cout << now << endl;
		return;
	}

	for (int i = 1; i < 10; i++) {
		if (i % 2 == 1 && isPrime(now * 10 + i)) {
			DFS(now * 10 + i, jaritsu + 1);
		}
	}
}

bool isPrime(int number) {
	for (int i = 2; i < number / 2; i++) {
		if (number % i == 0) return false;
	}
	return true;
}