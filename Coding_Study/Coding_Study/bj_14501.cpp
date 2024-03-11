/*
* 백준14501 퇴사
* 동적계획법
* 20240311
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<int, int> p;
vector<p> arr;
vector<int> D;

int main() {

	int N;
	cin >> N;

	D.resize(N + 2, 0);
	arr.resize(N + 2);
	
	int T, P;
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		arr[i].first = T;
		arr[i].second = P;
	}

	int max_value = -1;
	for (int i = 1; i <= N+1; i++) {
		D[i] = max(D[i], D[i - 1]);
		if (i + arr[i].first <= N+1) {
			D[i + arr[i].first] = max(D[i + arr[i].first], D[i] + arr[i].second);
			if (D[i + arr[i].first] > max_value) max_value = D[i + arr[i].first];
		}
	}

	cout << max_value;

	return 0;
}