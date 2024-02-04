#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 정수를 나선형으로 배치하기
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<vector<bool>> visited;

void DFS(vector<vector<int>>& answer, int cur_x, int cur_y, int n, int value, int mode) {
    if (value == pow(n, 2) + 1) return;
    answer[cur_y][cur_x] = value;
    visited[cur_y][cur_x] = true;

    int x = cur_x + dx[mode];
    int y = cur_y + dy[mode];
    if (x >= 0 && y >= 0 && x < n && y < n) {
        if (!visited[y][x] && answer[y][x] == 0) {
            DFS(answer, x, y, n, value + 1, mode);
        }
        else {
            int x = cur_x + dx[(mode + 1) % 4];
            int y = cur_y + dy[(mode + 1) % 4];
            DFS(answer, x, y, n, value + 1, (mode + 1) % 4);
        }
    }
    else {
        int x = cur_x + dx[(mode + 1) % 4];
        int y = cur_y + dy[(mode + 1) % 4];
        DFS(answer, x, y, n, value + 1, (mode + 1) % 4);
    }
}

vector<vector<int>> case1(int n) {
    vector<vector<int>> answer;

    answer.resize(n, vector<int>(0));
    visited.resize(n, vector<bool>(false));
    for (int i = 0; i < n; i++) {
        answer[i].resize(n, 0);
        visited[i].resize(n, false);
    }

    DFS(answer, 0, 0, n, 1, 0);

    return answer;
}

// 특별한 이차원 배열 2
int case2(vector<vector<int>> arr) {
    int answer = 1;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] != arr[j][i]) answer = 0;
        }
    }

    return answer;
}

// 정사각형으로 만들기
vector<vector<int>> case3(vector<vector<int>> arr) {
    vector<vector<int>> answer;

    if (arr.size() < arr[0].size()) {
        arr.resize(arr[0].size(), vector<int>(arr[0].size()));
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i].size() < arr.size()) {
                for (int k = 0; k < arr.size() - arr[i].size(); k++) {
                    arr[i].push_back(0);
                }
            }
        }
    }
    answer = arr;

    return answer;
}

// 이차원 배열 대각선 순회하기
int case4(vector<vector<int>> board, int k) {
    int answer = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (i + j <= k) answer += board[i][j];
        }
    }

    return answer;
}