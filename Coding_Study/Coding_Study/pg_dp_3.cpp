#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> D;
vector<vector<bool>> pools;

int main() {
    
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles;

    D.resize(101);
    pools.resize(101);
    for (int i = 0; i <= n; i++) {
        D[i].resize(101, 0);
        pools[i].resize(101, true);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            D[i][j] = 1;
        }
    }
    for (int i = 0; i < puddles.size(); i++) {
        pools[puddles[i][0]][puddles[i][1]] = false;
        D[puddles[i][0]][puddles[i][1]] = 0;
    }

    D[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (pools[i][j]) {
                D[i][j] = D[i - 1][j] + D[i][j - 1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}