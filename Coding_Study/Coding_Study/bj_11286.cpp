/*
* 백준11286 절댓값 힙 구하기
* 자료구조 - 큐
* 20240205
*/
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) { return true; }
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2) { return true; }
			else { return false; }
		}
		else { return false; }
	}
};

int main() {
	
	int N;
	cin >> N;

	priority_queue<int, vector<int>, cmp> pq;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num != 0) {
			pq.push(num);
		}
		else
		{
			if (pq.size() == 0) {
				cout << "0\n";
				continue;
			}

			int temp = pq.top();
			pq.pop();
			cout << temp << "\n";
		}
	}

	return 0;
}