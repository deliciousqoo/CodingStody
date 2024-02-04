#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool visited[101][101];
int X, Y;

void BFS(vector<vector<int>>& maps, int i, int j) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(i, j));

    while (!myqueue.empty()) {
        int cur_y = myqueue.front().first;
        int cur_x = myqueue.front().second;
        myqueue.pop();

        for (int k = 0; k < 4; k++) {
            int x = cur_x + dx[k];
            int y = cur_y + dy[k];

            if (x >= 0 && y >= 0 && x < X && y < Y) {
                if (!visited[y][x] && maps[y][x] != 0) {
                    visited[y][x] = true;
                    maps[y][x] = maps[cur_y][cur_x] + 1;
                    myqueue.push(make_pair(y, x));
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    X = maps[0].size();
    Y = maps.size();

    BFS(maps, 0, 0);

    if (visited[Y - 1][X - 1] == false) { answer = -1; }
    else { answer = maps[Y - 1][X - 1]; }

    return answer;
}