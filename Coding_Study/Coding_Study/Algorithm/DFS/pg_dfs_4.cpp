#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 10000;
bool dfs_check = false;
vector<bool> visited;

bool compareWords(string input1, string input2) {
    int count = 0;
    for (int i = 0; i < input1.length(); i++) {
        if (input1[i] == input2[i]) { count++; }
    }

    if (count >= input1.length() - 1) { return true; }
    else { return false; }
}

void DFS(vector<string> words, string now, string target, int depth) {
    if (now == target && depth < answer) {
        answer = depth;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && compareWords(now, words[i])) {
            visited[i] = true;
            DFS(words, words[i], target, depth + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    visited.resize(words.size(), false);
    DFS(words, begin, target, 0);

    if (answer == 10000) { answer = 0; }
    return answer;
}