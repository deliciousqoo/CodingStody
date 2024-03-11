/*
* 백준13398
* 동적계획법
* 20240311
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

vector<int> arr;
vector<vector<int>> D;

int main() {

	int n;
	cin >> n;

	D.resize(100001);
	arr.resize(100001);
	for (int i = 1; i <= 100000; i++) {
		D[i].resize(2, 0);
	}

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	D[1][0] = arr[1];
	D[1][1] = 0;
	int max_value = arr[1];
	for (int i = 2; i <= n; i++) {
		D[i][0] = max(arr[i], D[i - 1][0] + arr[i]);
		D[i][1] = max(D[i - 1][0], D[i - 1][1] + arr[i]);
		max_value = max(max_value, D[i][0]);
		max_value = max(max_value, D[i][1]);
	}

	cout << max_value;

	return 0;
}