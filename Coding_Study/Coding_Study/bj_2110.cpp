/*
* 백준2110 공유기 설치
* 이분탐색
* 20240308
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}