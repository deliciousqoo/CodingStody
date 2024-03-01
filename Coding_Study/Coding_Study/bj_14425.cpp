/*
* 백준14425 문자열 집합
* 집합과 맵
* 20240229
*/

//서적 참고 정답코드

#include <iostream>

using namespace std;

class Node {
public:
	Node* next[26];
	bool isEnd;
	Node() : isEnd(false) {
		fill(next, next + 26, nullptr);
	}

	~Node() {
		for (auto& child : next) {
			delete child;
		}
	}

	void insert(const char* key) {
		if (*key == 0) {
			isEnd = true;
		}
		else {
			int next_index = *key - 'a';
			if (next[next_index] == nullptr) {
				next[next_index] = new Node();
			}
			next[next_index]->insert(key + 1);
		}
	}

	Node* find(const char* key) {
		if (*key == 0) {
			return this;
		}
		int next_index = *key - 'a';

		if (next[next_index] == nullptr) {
			return nullptr;
		}
		return next[next_index]->find(key + 1);
	}
};

int main() {

	int N, M;
	cin >> N >> M;
	Node* root = new Node();

	char input[501];
	for (int i = 0; i < N; i++) {
		cin >> input;
		root->insert(input);
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		cin >> input;
		Node* result = root->find(input);

		if (result && result->isEnd) count++;
	}

	cout << count;

	return 0;
}