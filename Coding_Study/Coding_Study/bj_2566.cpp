/*
* 백준2566 최댓값
* 2차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<vector<int>> arr(9);

	int temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	int max = -1;
	int y, x;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				y = i;
				x = j;
			}
		}
	}

	cout << max << endl << y+1 << " " << x+1;

	return 0;
}