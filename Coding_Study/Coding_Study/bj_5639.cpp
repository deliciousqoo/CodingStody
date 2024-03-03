/*
* 백준5639 이진 검색 트리
* 트리
* 20240302
*/
#include <iostream>
#include <vector>

using namespace std;

int tree[1000001][2];
vector<int> inOrder;

void make_tree(int root_index, int left, int right) {
	if (right - left == 0) return;
	
	int i;
	for (i = left+1; i <= right; i++) {
		if (inOrder[i] > inOrder[root_index]) { break; }
	}
	
	if ((i-1)-left != 0) {
		tree[inOrder[root_index]][0] = inOrder[left+1];
		make_tree(left+1, left+1, i-1);
	}
	if (i <= right) {
		tree[inOrder[root_index]][1] = inOrder[i];
		make_tree(i, i, right);
	}
}

void preOrder(int now) {
	if (now == NULL) return;
	preOrder(tree[now][0]);
	preOrder(tree[now][1]);
	cout << now << "\n";
}

int main() {

	int num;
	while (cin >> num) {
		inOrder.push_back(num);
	}

	make_tree(0, 0, inOrder.size() - 1);
	preOrder(inOrder[0]);

	return 0;
}