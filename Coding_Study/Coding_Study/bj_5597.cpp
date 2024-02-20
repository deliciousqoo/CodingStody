/*
* 백준5597 과제 안 내신 분..?
* 1차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr(31, 0);
	
	int temp;
	for (int i = 0; i < 28; i++) {
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0) cout << i << endl;
	}

	return 0;
}