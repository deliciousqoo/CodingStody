/*
* 백준1753 최단경로
* 다익스트라 알고리즘
* 20240123
*/
#include <vector>
#include <queue>
#include <iostream>
#define INF 1000000

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> mlist;
vector<int> mdistance;
vector<bool> visited;
priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {

	int V, E, K;
	cin >> V >> E;
	cin >> K;

	mlist.resize(V + 1);
	mdistance.resize(V + 1);
	fill(mdistance.begin(), mdistance.end(), INF);
	visited.resize(V + 1);
	fill(visited.begin(), visited.end(), false);

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		mlist[u].push_back(make_pair(v, w));
	}

	q.push(make_pair(0, K));
	mdistance[K] = 0;

	while (!q.empty()) {
		edge current = q.top();
		q.pop();
		int c_v = current.second;
		if (visited[c_v]) { 
			continue; 
		}
		visited[c_v] = true;

		for (int i = 0; i < mlist[c_v].size(); i++) {
			edge temp = mlist[c_v][i];
			int next = temp.first;
			int value = temp.second;
			
			if (mdistance[next] > mdistance[c_v] + value) {
				mdistance[next] = mdistance[c_v] + value;
				q.push(make_pair(mdistance[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i]) {
			cout << mdistance[i] << "\n";;
		}
		else
		{
			cout << "INF" << "\n";
		}
	}

	return 0;
}