/*
* 백준25305 커트라인
* 정렬
* 20240229
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	vector<int> arr;

	int N, k, x;
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end(), greater<>());
	cout << arr[k-1];

	return 0;
}