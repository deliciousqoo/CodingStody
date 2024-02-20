/*
* 백준10807 개수 세기
* 1차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, v;
	cin >> N;

	vector<int> arr;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> v;

	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == v) count++;
	}

	cout << count;

	return 0;
}