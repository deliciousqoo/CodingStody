//프로그래머스 네트워크

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;

void DFS(int now) {
    if (visited[now]) return;
    visited[now] = true;

    for (int i : arr[now]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    arr.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (i != j && computers[i][j] == 1) arr[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
            answer++;
        }
    }

    return answer;
}