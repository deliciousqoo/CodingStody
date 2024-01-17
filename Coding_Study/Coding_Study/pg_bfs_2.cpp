#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int maze[101][101];
bool visited[101][101];

bool checkOutline(int x, int y) {
    if (maze[y][x] == 0) return false;

    int temp = 1;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (temp == 0) break;
            temp *= maze[i][j];
        }
    }

    if (temp == 0) return true;
    else return false;
}

void BFS(int input_x, int input_y) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(input_y, input_x));
    visited[input_y][input_x] = false;
    
    while (!myqueue.empty()) {
        int cur_x = myqueue.front().second;
        int cur_y = myqueue.front().first;
        myqueue.pop();

        for (int i = 0; i < 4; i++) {
            int x = cur_x + dx[i];
            int y = cur_y + dy[i];

            if (visited[y][x] && maze[y][x] != 0) {
                visited[y][x] = false;
                maze[y][x] = maze[cur_y][cur_x] + 1;
                myqueue.push(make_pair(y, x));
            }
        }
    }
}

int main() {
    int answer = 0;

    vector<vector<int>> rectangle = { {1, 1, 8, 4 }
                                    , { 2, 2, 4, 9 }
                                    , { 3, 6, 9, 8 }
                                    , { 6, 3, 7, 7 } };
    int characterX = 9;
    int characterY = 7;
    int itemX = 6;
    int itemY = 1;
    for (int i = 0; i < rectangle.size(); i++) {
        for (int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) {
            for (int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) {
                maze[y][x] = 1;
            }
        }
    }
    
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            visited[i][j] = checkOutline(j, i);
        }
    }

    BFS(characterX*2, characterY*2);

    cout << endl;
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            printf("%3d", maze[i][j]);
        }
        cout << endl;
    }


    cout << maze[itemY*2][itemX*2];

    return answer;
}