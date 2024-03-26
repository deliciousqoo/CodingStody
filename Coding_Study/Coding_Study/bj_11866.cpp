/*
* 백준11866 요세푸스 문제 0
* 스택, 큐, 덱
* 20240325
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
queue<int> myDeque;
vector<int> arr;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		myDeque.push(i);
	}

	int count = 1;
	while (!myDeque.empty()) {
		if (count == K) {
			arr.push_back(myDeque.front());
			myDeque.pop();
			count = 1;
		}
		else
		{
			myDeque.push(myDeque.front());
			myDeque.pop();
			count++;
		}
	}

	cout << "<";
	for (int i = 0; i < N; i++) {
		cout << arr[i];
		if (i != N - 1) cout << ", ";
	}
	cout << ">";

	return 0;
}