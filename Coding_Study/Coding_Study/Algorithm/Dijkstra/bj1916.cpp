/*
* 백준1916 최소비용 구하기
* 다익스트라 알고리즘
* 20240123
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> mlist;
vector<bool> visited;
vector<int> mdistance;
priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {
	
	int N, M;
	cin >> N;
	cin >> M;

	mlist.resize(N + 1);
	mdistance.resize(N + 1, INT_MAX);
	visited.resize(N + 1, false);

	int u, v, w;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		mlist[u].push_back(make_pair(v, w));
	}

	int A, B;
	cin >> A >> B;

	q.push(make_pair(0, A));
	mdistance[A] = 0;

	while (!q.empty()) {
		edge current = q.top();
		q.pop();
		int cv = current.second;
		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int next = temp.first;
			int value = temp.second;

			if (mdistance[next] > mdistance[cv] + value) {
				mdistance[next] = mdistance[cv] + value;
				q.push(make_pair(mdistance[next], next));
			}
		}
	}

	cout << mdistance[B];

	return 0;
}