#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<vector<int>> temp_table;
vector<vector<int>> visited;
int arr_size;

void rotate_vector(vector<vector<int>>& table, vector<vector<int>> temp) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            temp[j][table.size() - 1 - i] = table[i][j];
        }
    }
    table = temp;
}

void DFS(int input_y, int input_x, vector<vector<int>>& game_board, vector<vector<int>>& table) {
    if (visited[input_y][input_x] == 1) { return; }
    visited[input_y][input_x] = 1;

    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            if (table[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int cur_x = input_x + dx[k];
                    int cur_y = input_y + dy[k];
                    int table_x = j + dx[k];
                    int table_y = i + dy[k];
                    if (cur_x >= 0 && cur_y >= 0 && cur_x < game_board[0].size() && cur_y < game_board.size()) {
                        if (visited[cur_y][cur_x] == 0 && table[table_y][table_x] == 1 && game_board[cur_y][cur_x] == 0) {
                            DFS(cur_y, cur_x, game_board, table);
                            visited[cur_y][cur_x] = 0;
                        }
                    }
                }
            }
        }
    }
}

int main() {

    vector<vector<int>> game_board = { {1, 1, 0, 0, 1, 0},{0, 0, 1, 0, 1, 0},{0, 1, 1, 0, 0, 1},{1, 1, 0, 1, 1, 1},{1, 0, 0, 0, 1, 0},{0, 1, 1, 1, 0, 0} };
    vector<vector<int>> table = { {1, 0, 0, 1, 1, 0},{1, 0, 1, 0, 1, 0},{0, 1, 1, 0, 1, 1},{0, 0, 1, 0, 0, 0},{1, 1, 0, 1, 1, 0},{0, 1, 0, 0, 0, 0} };
    int answer = -1;

    arr_size = game_board.size();
    visited = game_board;
    temp_table.resize(arr_size, vector<int>(0));
    for (int i = 0; i < arr_size; i++) {
        temp_table[i].resize(arr_size, 0);
    }


    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[0].size(); j++) {
            if (game_board[i][j] == 0) {
                DFS(i, j, game_board, table);
            }
        }
    }

    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[0].size(); j++) {
            cout << game_board[i][j];
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[0].size(); j++) {
            cout << visited[i][j];
        }
        cout << endl;
    }

    return 0;
}