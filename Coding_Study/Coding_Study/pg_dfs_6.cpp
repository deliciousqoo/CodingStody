/*
* 프로그래머스 경주로 건설
* DFS
* 20240313
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int min_cost = INT_MAX;

void DFS(vector<vector<int>> maze, vector<vector<bool>> visited, int now_y, int now_x, int dir, int cost) {
    if (now_y == maze.size() - 1 && now_x == maze.size() - 1) {
        if (cost < min_cost) min_cost = cost;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int y = now_y + dy[i];
        int x = now_x + dx[i];

        if (x >= 0 && y >= 0 && y <= maze.size() - 1 && x <= maze.size() - 1) {
            if (!visited[y][x]) {
                visited[y][x] = true;
                if (dir != i) {
                    DFS(maze, visited, y, x, i, cost + 600);
                }
                else {
                    DFS(maze, visited, y, x, i, cost + 100);
                }
                visited[y][x] = false;
            }
        }
    }

}

int main() {

    vector<vector<int>> board = { {0, 0, 0},{0, 0, 0},{0, 0, 0} };
    int answer = 0;

    vector<vector<bool>> visited;

    visited.resize(board.size() + 1);

    for (int i = 0; i < board.size(); i++) {
        visited[i].resize(board.size() + 1);
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 1) {
                visited[i][j] = true;
            }
        }
    }

    DFS(board, visited, 0, 1, 0, 100);
    DFS(board, visited, 1, 0, 1, 100);

    /*for(int i=0;i<maze.size();i++) {
        for(int j=0;j<maze.size();j++) {
            printf("%2d ", maze[i][j]);
        }
        cout << endl;
    }*/

    cout << min_cost;

    return answer;
}
