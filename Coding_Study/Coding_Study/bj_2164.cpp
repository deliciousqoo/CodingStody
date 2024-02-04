/*
* 백준2164 카드 게임
* 자료구조 - 큐
* 20240205
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	queue<int> myQueue;

	for (int i = 1; i <= N; i++) {
		myQueue.push(i);
	}

	while (myQueue.size() != 1) {
		myQueue.pop();
		int temp = myQueue.front();
		myQueue.pop();
		myQueue.push(temp);
	}

	cout << myQueue.front();

	return 0;
}