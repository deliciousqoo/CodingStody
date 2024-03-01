/*
* 백준1991 트리 순회
* 트리
* 20240301
*/
#include <iostream>

using namespace std;

int tree[26][2];

void preOrder(int now) {
	if (now == -1) return;
	cout << (char)(now + 'A');
	preOrder(tree[now][0]);
	preOrder(tree[now][1]);
}

void inOrder(int now) {
	if (now == -1) return;
	inOrder(tree[now][0]);
	cout << (char)(now + 'A');
	inOrder(tree[now][1]);
}

void postOrder(int now) {
	if (now == -1) return;
	postOrder(tree[now][0]);
	postOrder(tree[now][1]);
	cout << (char)(now + 'A');
}

int main() {

	int N;
	cin >> N;

	char node, left, right;
	for (int i = 0; i < N; i++) {
		cin >> node >> left >> right;

		if(left != '.') tree[node - 'A'][0] = left - 'A';
		else tree[node - 'A'][0] = -1;
		if (right != '.') tree[node - 'A'][1] = right - 'A';
		else tree[node - 'A'][1] = -1;
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";

	return 0;
}