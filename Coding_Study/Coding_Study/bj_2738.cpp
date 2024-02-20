/*
* 백준2738 행렬 덧셈
* 2차원 배열
* 20240220
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<int>> A(3);
	vector<vector<int>> B(3);

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			A[i].push_back(temp);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			B[i].push_back(temp);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] + B[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}