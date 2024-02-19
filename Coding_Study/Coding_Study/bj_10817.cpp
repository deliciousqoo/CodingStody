/*
* 백준10817 세 수
* 정렬
* 20240219
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> arr;
	int temp;

	for (int i = 0; i < 3; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	cout << arr[1];

	return 0;
}