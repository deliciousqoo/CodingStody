/*
* 백준24511 queuestack
* 스택, 큐, 덱
* 20240325
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<vector<int>> arr;
vector<int> check;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input, M;;
	cin >> N;

	arr.resize(N);
	check.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> check[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i].push_back(input);
	}

	cin >> M;
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			if (check[j] == 0) {
				temp = arr[j][0];
				arr[j][0] = input;
				input = temp;
			}
		}
		cout << input << " ";
	}

	return 0;
}