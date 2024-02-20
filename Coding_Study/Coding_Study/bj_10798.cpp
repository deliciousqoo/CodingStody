/*
* 백준10798 세로읽기
* 2차원 배열
* 20240220
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	vector<vector<char>> arr(5);

	string temp;
	for (int i = 0; i < 5; i++) {
		getline(cin, temp);
		for (int j = 0; j < 15; j++) {
			if (j < temp.length()) arr[i].push_back(temp[j]);
			else arr[i].push_back(' ');
		}
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if(arr[j][i] != ' ') cout << arr[j][i];
		}
	}

	return 0;
}