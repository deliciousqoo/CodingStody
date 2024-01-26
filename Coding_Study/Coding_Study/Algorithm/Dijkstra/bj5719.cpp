/*
* 백준5719 거의 최단 경로
* 다익스트라 알고리즘
* 20240124
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstring>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> mlist;
vector<int> mdistance;
vector<bool> visited;
priority_queue<edge, vector<edge>, greater<edge>> pq;
vector<vector<edge>> route;
bool deleted_check[500][500];

void dijkstra(int start) {
	pq.push(make_pair(0, start));
	mdistance[start] = 0;

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		int cv = current.second;

		if (current.first > mdistance[cv]) continue;
		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int next = temp.first;
			int value = temp.second;

			if (mdistance[next] > value + mdistance[cv]) {
				mdistance[next] = value + mdistance[cv];
				pq.push(make_pair(mdistance[next], next));

				route[next].clear();
				route[next].push_back(make_pair(cv, next));
			}
			else if (mdistance[next] == value + mdistance[cv]) {
				route[next].push_back(make_pair(cv, next));
			}
		}
	}
}

void dijkstra_deleted(int start) {
	pq.push(make_pair(0, start));
	mdistance[start] = 0;

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		int cv = current.second;

		if (current.first > mdistance[cv]) continue;
		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int next = temp.first;
			int value = temp.second;

			if (deleted_check[cv][next]) continue;

			if (mdistance[next] > value + mdistance[cv]) {
				mdistance[next] = value + mdistance[cv];
				pq.push(make_pair(mdistance[next], next));
			}
		}
	}
}

void DFS(int now) {
	for (edge i : route[now]) {
		if (deleted_check[i.first][i.second]) return;
		deleted_check[i.first][i.second] = true;
		DFS(i.first);
	}
}

int main() {

	int N, M, S, D;

	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		mdistance.resize(N, INT_MAX);
		visited.resize(N, false);
		mlist.resize(N);
		route.resize(N);

		cin >> S >> D;
		int U, V, P;
		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			mlist[U].push_back(make_pair(V, P));
		}

		dijkstra(S);
		DFS(D);

		fill(visited.begin(), visited.end(), false);
		fill(mdistance.begin(), mdistance.end(), INT_MAX);
		dijkstra_deleted(S);

		if (mdistance[D] != INT_MAX) cout << mdistance[D] << '\n';
		else cout << "-1" << '\n';

		memset(deleted_check, false, sizeof(deleted_check));
		mdistance.clear();
		visited.clear();
		mlist.clear();
		route.clear();
	}

	return 0;
}