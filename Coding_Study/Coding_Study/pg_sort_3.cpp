/*
* 프로그래머스 가장 큰 수
* 정렬
* 20240219
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    int max = -1;
    for (int i = 0; i < citations.size(); i++) {
        int temp = min(i + 1, citations[i]);
        if (temp > max) { max = temp; }
    }

    return max;
}