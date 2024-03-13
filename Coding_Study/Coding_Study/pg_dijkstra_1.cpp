#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

typedef pair<int, int> edge; //first: weight, second: node
vector<vector<edge>> mlist;
vector<bool> visited;
vector<int> mdistance1;
vector<int> mdistance2;
priority_queue<edge, vector<edge>, greater<edge>> pq;

void Dijkstra1(int start) {
	pq.push(make_pair(0, start));
	mdistance1[start] = 0;

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		int cv = current.second;

		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int value = temp.first;
			int next = temp.second;

			if (mdistance1[next] > mdistance1[cv] + value) {
				mdistance1[next] = mdistance1[cv] + value;
				pq.push(make_pair(mdistance1[next], next));
			}
		}
	}
}

void Dijkstra2(int start) {
	pq.push(make_pair(0, start));
	mdistance2[start] = 0;

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		int cv = current.second;

		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < mlist[cv].size(); i++) {
			edge temp = mlist[cv][i];
			int value = temp.first;
			int next = temp.second;

			if (mdistance2[next] > mdistance2[cv] + value) {
				mdistance2[next] = mdistance2[cv] + value;
				pq.push(make_pair(mdistance2[next], next));
			}
		}
	}
}

int main() {
	string numbers = "51238";
	int answer = 0;

	mlist.resize(12);
	visited.resize(12);
	mdistance1.resize(12, INT_MAX);
	mdistance2.resize(12, INT_MAX);

	mlist[0].push_back(make_pair(2, 8));
	mlist[0].push_back(make_pair(2, 10));
	mlist[0].push_back(make_pair(2, 11));
	mlist[0].push_back(make_pair(3, 7));
	mlist[0].push_back(make_pair(3, 9));

	mlist[1].push_back(make_pair(2, 2));
	mlist[1].push_back(make_pair(2, 4));
	mlist[1].push_back(make_pair(3, 5));

	mlist[2].push_back(make_pair(2, 1));
	mlist[2].push_back(make_pair(2, 3));
	mlist[2].push_back(make_pair(2, 5));
	mlist[2].push_back(make_pair(3, 4));
	mlist[2].push_back(make_pair(3, 6));

	mlist[3].push_back(make_pair(2, 2));
	mlist[3].push_back(make_pair(2, 6));
	mlist[3].push_back(make_pair(3, 5));

	mlist[4].push_back(make_pair(2, 1));
	mlist[4].push_back(make_pair(2, 5));
	mlist[4].push_back(make_pair(2, 7));
	mlist[4].push_back(make_pair(3, 2));
	mlist[4].push_back(make_pair(3, 8));

	mlist[5].push_back(make_pair(2, 2));
	mlist[5].push_back(make_pair(2, 4));
	mlist[5].push_back(make_pair(2, 6));
	mlist[5].push_back(make_pair(2, 8));
	mlist[5].push_back(make_pair(3, 1));
	mlist[5].push_back(make_pair(3, 3));
	mlist[5].push_back(make_pair(3, 7));
	mlist[5].push_back(make_pair(3, 9));

	mlist[6].push_back(make_pair(2, 3));
	mlist[6].push_back(make_pair(2, 5));
	mlist[6].push_back(make_pair(2, 9));
	mlist[6].push_back(make_pair(3, 2));
	mlist[6].push_back(make_pair(3, 8));

	mlist[7].push_back(make_pair(2, 4));
	mlist[7].push_back(make_pair(2, 8));
	mlist[7].push_back(make_pair(2, 10));
	mlist[7].push_back(make_pair(3, 5));
	mlist[7].push_back(make_pair(3, 0));

	mlist[8].push_back(make_pair(2, 5));
	mlist[8].push_back(make_pair(2, 7));
	mlist[8].push_back(make_pair(2, 9));
	mlist[8].push_back(make_pair(2, 0));
	mlist[8].push_back(make_pair(3, 4));
	mlist[8].push_back(make_pair(3, 6));
	mlist[8].push_back(make_pair(3, 10));
	mlist[8].push_back(make_pair(3, 11));

	mlist[9].push_back(make_pair(2, 6));
	mlist[9].push_back(make_pair(2, 8));
	mlist[9].push_back(make_pair(2, 11));
	mlist[9].push_back(make_pair(3, 5));
	mlist[9].push_back(make_pair(3, 0));

	mlist[10].push_back(make_pair(2, 7));
	mlist[10].push_back(make_pair(2, 0));
	mlist[10].push_back(make_pair(3, 8));

	mlist[11].push_back(make_pair(2, 9));
	mlist[11].push_back(make_pair(2, 0));
	mlist[11].push_back(make_pair(3, 8));

	int left = 4, right = 6;
	Dijkstra1(4);
	fill(visited.begin(), visited.end(), false);
	Dijkstra2(6);
	int cur = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == '*') cur = 10;
		else if (numbers[i] == '#') cur = 11;
		else
		{
			cur = numbers[i] - '0';
		}

		if (cur == left || cur == right) {
			answer += 1;
			continue;
		}

		if (mdistance1[cur] < mdistance2[cur]) {
			answer += mdistance1[cur];
			fill(visited.begin(), visited.end(), false);
			fill(mdistance1.begin(), mdistance1.end(), INT_MAX);
			Dijkstra1(cur);
			left = cur;
		}
		else
		{
			answer += mdistance2[cur];
			fill(visited.begin(), visited.end(), false);
			fill(mdistance2.begin(), mdistance2.end(), INT_MAX);
			Dijkstra2(cur);
			right = cur;
		}
	}
	cout << answer;

	return answer;
}