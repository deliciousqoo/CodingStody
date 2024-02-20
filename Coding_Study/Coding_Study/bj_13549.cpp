/*
* 백준13549 숨바꼭질 3
* 다익스트라 알고리즘
* 20240220
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> mlist;
vector<int> mdistance;
priority_queue<edge, vector<edge>, greater<edge>> pq;
vector<bool> visited;

void Dijkstra(int start) {
	pq.push(make_pair(0, start));
	mdistance[start] = 0;

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		int cv = current.second;
		
		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int next = temp.first;
			int value = temp.second;

			if (mdistance[next] > mdistance[cv] + value) {
				mdistance[next] = mdistance[cv] + value;
				pq.push(make_pair(mdistance[next], next));
			}
		}
	}
}

int main() {

	int N, K;
	cin >> N >> K;

	mlist.resize(100001);
	visited.resize(100001);
	mdistance.resize(100001, INT_MAX);

	for (int i = 0; i <= 100000; i++) {
		if (i - 1 >= 0) mlist[i].push_back(make_pair(i-1, 1));
		if (i + 1 <= 100000 && i != 1) mlist[i].push_back(make_pair(i + 1, 1));
		if (i * 2 <= 100000) mlist[i].push_back(make_pair(i * 2, 0));
	}

	Dijkstra(N);
	cout << mdistance[K];

	return 0;
}