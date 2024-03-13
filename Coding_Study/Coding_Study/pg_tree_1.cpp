/*
* 프로그래머스 길 찾기 게임
* 트리
* 20240313
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<vector<int>> answer;

bool cmp(vector<int> a1, vector<int> a2) {
    if (a1[1] > a2[1]) return true;
    else return false;
}

void make_tree(int root, int new_node, int index) {
    if (new_node < root) {
        if (tree[root][1] == -1) {
            tree[new_node][0] = index;
            tree[root][1] = new_node;
        }
        else {
            make_tree(tree[root][1], new_node, index);
        }
    }
    else if (new_node > root) {
        if (tree[root][2] == -1) {
            tree[new_node][0] = index;
            tree[root][2] = new_node;
        }
        else {
            make_tree(tree[root][2], new_node, index);
        }
    }
}

void preOrder(int now) {
    if (now == -1) return;
    answer[0].push_back(tree[now][0]);
    preOrder(tree[now][1]);
    preOrder(tree[now][2]);
}

void postOrder(int now) {
    if (now == -1) return;
    postOrder(tree[now][1]);
    postOrder(tree[now][2]);
    answer[1].push_back(tree[now][0]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    answer.resize(2);
    tree.resize(100001);
    for (int i = 0; i < tree.size(); i++) {
        tree[i].resize(3, -1);
    }

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);

    tree[nodeinfo[0][0]][0] = nodeinfo[0][2];
    for (int i = 1; i < nodeinfo.size(); i++) {
        make_tree(nodeinfo[0][0], nodeinfo[i][0], nodeinfo[i][2]);
    }

    preOrder(nodeinfo[0][0]);
    postOrder(nodeinfo[0][0]);

    return answer;
}