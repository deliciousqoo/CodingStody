/*
* 백준1377 버블 소트
* 버블 정렬
* 20240207
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pairs;

int main() {

    int N;
    cin >> N;

    vector<pairs> A(N);

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A[i].first = temp;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int max = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].second - i > max) {
            max = A[i].second - i;
        }
    }

    cout << max + 1;

	return 0;
}