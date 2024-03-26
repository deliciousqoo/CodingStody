/*
* 백준24511 queuestack
* 스택, 큐, 덱
* 20240326
*/
#include <iostream>
#include <queue>

using namespace std;
deque<int> myDeque;
vector<int> check;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input, M;;
	cin >> N;

	check.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> check[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (check[i] == 0) {
			myDeque.push_front(input);
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		myDeque.push_back(input);
		cout << myDeque.front() << " ";
		myDeque.pop_front();
	}

	return 0;
}