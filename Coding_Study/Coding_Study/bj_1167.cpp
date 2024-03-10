#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> arr;
vector<bool> visited;
vector<int> dist;

void BFS(int now, int weight) {
	queue<int> myqueue;
	myqueue.push(now);
	visited[now] = true;
	

	while (!myqueue.empty()) {
		int cur = myqueue.front();
		myqueue.pop();

		for (pair<int, int> i : arr[cur]) {
			if (!visited[i.first]) {
				myqueue.push(i.first);
				visited[i.first] = true;
				dist[i.first] = i.second + dist[cur];
			}
		}
	}
}

int main() {

	int V;
	cin >> V;
	
	arr.resize(V + 1);
	dist.resize(V + 1, 0);
	visited.resize(V + 1, false);

	int node, edge, weight;
	for (int i = 0; i < V; i++) {
		cin >> node;
		while (1) {
			cin >> edge;
			if (edge == -1) break;
			cin >> weight;
			
			arr[node].push_back(make_pair(edge, weight));
		}
	}

	BFS(1, 0);

	int max = -1;
	int max_index;
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] > max) {
			max = dist[i];
			max_index = i;
		}
	}

	visited.clear();
	visited.resize(V + 1, false);
	dist.clear();
	dist.resize(V + 1, 0);
	BFS(max_index, 0);

	max = -1;
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] > max) {
			max = dist[i];
		}
	}

	cout << max;

	return 0;
}