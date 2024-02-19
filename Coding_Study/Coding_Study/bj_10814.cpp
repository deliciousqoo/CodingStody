/*
* 백준10814 나이순 정렬
* 정렬
* 20240219
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<string>> arr(100001);
	int temp_i;
	string temp_s;
	for (int i = 0; i < N; i++) {
		cin >> temp_i >> temp_s;
		arr[temp_i].push_back(temp_s);
	}

	for (int i = 1; i < 100001; i++) {
		if (arr[i].size() != 0) {
			for (int j = 0; j < arr[i].size(); j++) {
				cout << i << " " << arr[i][j] << "\n";
			}
		}
	}

	return 0;
}