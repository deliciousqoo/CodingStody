#include <string>
#include <vector>
#include <math.h>
#include <limits.h>
#include <iostream>

using namespace std;

vector<int> D;
vector<int> arr;


void DP(int N, int num, int count) {
    if (count > 8) return;
    cout << N << " " << num << endl;

    if (num + N <= 32000 && num + N >= 0) {
        D[num + N] = min(D[num + N], D[num] + D[N]);
        DP(N, num + N, D[num+N] + count);
    }

    if (num * N <= 32000 && num * N >= 0) {
        D[num * N] = min(D[num * N], D[num] + D[N]);
        DP(N, num * N, D[num * N] + count);
    }

    if (num - N <= 32000 && num - N >= 0) {
        D[num - N] = min(D[num - N], D[num] + D[N]);
        DP(N, num - N, D[num - N] + count);
    }

    if (num / N <= 32000 && num / N >= 0) {
        D[num / N] = min(D[num / N], D[num] + D[N]);
        DP(N, num / N, D[num / N] + count);
    }
}


int main() {
    int N = 5;
    int number = 26;

    D.resize(32001, INT_MAX);

    string temp;
    for (int i = 0; i < 5; i++) {
        temp = "";
        for (int j = 0; j <= i; j++) temp.push_back(N + '0');
        if (stoi(temp) <= 32000) {
            arr.push_back(stoi(temp));
            D[stoi(temp)] = i + 1;
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            DP(arr[i], arr[j], to_string(arr[i]).length());
        }
    }

    cout << D[number];

    return 0;
}