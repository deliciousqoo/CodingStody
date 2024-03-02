/*
* 백준2263 트리의 순회
* 트리
* 20240302
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> inOrder;
vector<int> postOrder;

void make_tree(int node, int left_inOrder, int right_inOrder, int left_postOrder, int right_postOrder) {
	if (right_inOrder - left_inOrder <= 0) return;

	int node_index = 0;
	for (int i = left_inOrder; i <= right_inOrder; i++) {
		if (inOrder[i] == node) {
			node_index = i;
			break;
		}
	}
	int left_size = node_index - left_inOrder;
	int right_size = right_inOrder - node_index;

	if (left_size != 0) {
		tree[node][0] = postOrder[left_postOrder + left_size - 1];
		make_tree(tree[node][0], left_inOrder, node_index -1, left_postOrder, left_postOrder + left_size - 1);
	}
	if (right_size != 0) {
		tree[node][1] = postOrder[right_postOrder - 1];
		make_tree(tree[node][1], node_index+1, right_inOrder, left_postOrder + left_size, left_postOrder + left_size + right_size - 1);
	}
}

void preOrder(int now) {
	if (now == NULL) return;
	cout << now << " ";
	preOrder(tree[now][0]);
	preOrder(tree[now][1]);
}

int main() {

	int N;
	cin >> N;

	tree.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		tree[i].resize(2, NULL);
	}

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inOrder.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		postOrder.push_back(input);
	}

	make_tree(postOrder[postOrder.size() - 1], 0, inOrder.size() - 1, 0, postOrder.size() - 1);
	preOrder(postOrder[postOrder.size() - 1]);

	return 0;
}