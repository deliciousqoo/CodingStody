//프로그래머스 여행경로

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

vector<bool> visited;
vector<vector<string>> temp;
string ans_string = "";


void DFS(vector<vector<string>>& tickets, string now, string path, int depth) {
    if (depth == tickets.size() && ans_string.length() == 0) {
        cout << path << endl;
        ans_string = path;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == now && !visited[i]) {
            visited[i] = true;
            DFS(tickets, tickets[i][1], path + tickets[i][1], depth + 1);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    visited.resize(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS(tickets, "ICN", "ICN", 0);

    for (int i = 0; i < ans_string.length(); i += 3) {
        answer.push_back(ans_string.substr(i, 3));
    }

    return answer;
}