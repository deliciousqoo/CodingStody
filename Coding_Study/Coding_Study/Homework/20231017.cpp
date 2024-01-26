#include <string>
#include <vector>

using namespace std;

//수열과 구간 쿼리 4
vector<int> case1(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++) {
        for (int j = queries[i][0]; j <= queries[i][1]; j++) {
            if (j % queries[i][2] == 0) {
                arr[j] += 1;
            }
        }
    }

    answer = arr;
    return answer;
}

//배열 만들기 
vector<int> case2(int l, int r) {
    vector<int> answer;

    for (int i = l; i <= r; i++) {
        if ((i % 10 == 5 || i % 10 == 0) && 
            ((i % 100) / 10 == 5 || (i % 100) / 10 == 0) && 
            ((i % 1000) / 100 == 5 || (i % 1000) / 100 == 0) && 
            ((i % 10000) / 1000 == 5 || (i % 10000) / 1000 == 0) && 
            ((i % 100000) / 10000 == 5 || (i % 100000) / 10000 == 0) && 
            ((i % 1000000) / 100000 == 5 || (i % 1000000) / 100000 == 0)) answer.push_back(i);
    }

    if (answer.size() == 0) answer.push_back(-1);

    return answer;
}

//카운트 업
vector<int> case3(int start_num, int end_num) {
    vector<int> answer;

    for (int i = start_num; i <= end_num; i++) {
        answer.push_back(i);
    }

    return answer;
}

//콜라츠 수열 만들기
vector<int> case4(int n) {
    vector<int> answer;

    while (n != 1) {
        answer.push_back(n);
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    answer.push_back(n);

    return answer;
}

//배열 만들기 4
vector<int> case5(vector<int> arr) {
    vector<int> stk;

    int i = 0;

    while (i < arr.size()) {
        if (stk.size() == 0) {
            stk.push_back(arr[i]);
            i++;
        }
        else if (stk[stk.size() - 1] < arr[i]) {
            stk.push_back(arr[i]);
            i++;
        }
        else if (stk[stk.size() - 1] >= arr[i]) {
            stk.pop_back();
        }
    }

    return stk;
}