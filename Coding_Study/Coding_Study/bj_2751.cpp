/*
* ����2751 �� �����ϱ� 2
* ����, DFS
* 20240219
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, temp;
	cin >> N;

	vector<int> arr;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}