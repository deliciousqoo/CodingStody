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
	tree[root_index][0] = inOrder[root_index + 1];
}

int main() {

	int num;
	while (cin >> num) {
		inOrder.push_back(num);
	}

	//for (int i = 0; i < inOrder.size(); i++) cout << inOrder[i];
	
	make_tree(0, 0, inOrder.size() - 1);

	return 0;
}