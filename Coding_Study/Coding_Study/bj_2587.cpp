/*
* 백준2587 대표값2
* 정렬
* 20240229
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	vector<int> arr;

	int input, total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		arr.push_back(input);
		total += input;
	}

	sort(arr.begin(), arr.end(), less<>());

	cout << total / 5 << endl << arr[2];

	return 0;
}