/*
* 백준1854 K번째 최단경로 찾기
* 다익스트라 알고리즘
* 20240123
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> mlist;
priority_queue<int> mdistance[1001];
queue<edge> q;

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	mlist.resize(n + 1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mlist[a].push_back(make_pair(b, c));
	}
	
	q.push(make_pair(0, 1));
	mdistance[1].push(0);

	while (!q.empty()) {
		edge current = q.front();
		q.pop();
		int cv = current.second;
		if (mdistance[cv].size() > k) continue;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int next = temp.first;
			int value = temp.second;
			if (mdistance[next].size() < k) {
				mdistance[next].push(value + current.first);
				q.push(make_pair(value + current.first, next));
			}
			else if (mdistance[next].top() > value + current.first) {
				mdistance[next].pop();
				mdistance[next].push(value + current.first);
				q.push(make_pair(value + current.first, next));
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (mdistance[i].size() == k) {
			cout << mdistance[i].top() << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}

	return 0;
}
