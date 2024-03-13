/*
* 프로그래머스 정수 삼각형
* 동적계획법
* 20240313
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> D;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    D.resize(triangle.size() + 1);
    for (int i = 1; i <= triangle.size(); i++) {
        D[i].resize(501, -1);
    }

    D[1].push_back(7);
    for (int i = 1; i <= triangle.size(); i++) {
        for (int j = 1; j <= triangle[i - 1].size(); j++) {
            D[i][j] = triangle[i - 1][j - 1];
            if (i > 1) {
                D[i][j] = D[i][j] + max(D[i - 1][j - 1], D[i - 1][j]);
            }
        }
    }

    int max_value = -1;
    for (int i = 0; i < D[triangle.size()].size(); i++) {
        if (D[triangle.size()][i] > max_value) max_value = D[triangle.size()][i];
    }
    answer = max_value;

    return answer;
}