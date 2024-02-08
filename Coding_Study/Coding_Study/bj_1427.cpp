/*
* 백준1427 소트인사이드
* 선택 정렬
* 20240207
*/
#include <vector>
#include <iostream>

using namespace std;

int main() {

	string num;
	cin >> num;

	vector<int> arr(num.length());

	for (int i = 0; i < num.length(); i++) {
		arr[i] = num[i] - '0';
	}

	int max = -1;
	int max_index, temp;
	for (int i = 0; i < arr.size(); i++) {
		max = -1;
		for (int j = i; j < arr.size(); j++) {
			if (arr[j] > max) {
				max = arr[j];
				max_index = j;
			}
		}
		temp = arr[i];
		arr[i] = max;
		arr[max_index] = temp;
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}


	return 0;
}