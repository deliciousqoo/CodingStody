/*
* 프로그래머스 N으로 표현
* 동적계획법
* 20240313
*/
#include <string>
#include <vector>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <set>

using namespace std;

vector<int> D;
vector<set<long long>> arr;

int solution(int N, int number) {
    int answer = 0;

    D.resize(32001, INT_MAX);
    arr.resize(9);

    string temp;
    for (int i = 1; i <= 8; i++) {
        temp = "";
        for (int j = 1; j <= i; j++) temp.push_back(N + '0');
        arr[i].insert(stoi(temp));
        if (stoi(temp) <= 32000) D[stoi(temp)] = i;
    }

    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int a : arr[j]) {
                for (int b : arr[i - j]) {
                    arr[i].insert(a + b);
                    if (a + b >= 0 && a + b <= 32000) D[a + b] = min(D[a + b], i);
                    arr[i].insert(a - b);
                    if (a - b >= 0 && a - b <= 32000) D[a - b] = min(D[a - b], i);
                    arr[i].insert(a * b);
                    if (a * b >= 0 && a * b <= 32000) D[a * b] = min(D[a * b], i);
                    if (b > 0) {
                        arr[i].insert(a / b);
                        if (a / b >= 0 && a / b <= 32000) D[a / b] = min(D[a / b], i);
                    }
                }
            }
        }
    }

    answer = D[number];
    if (D[number] > 8) answer = -1;

    return answer;
}