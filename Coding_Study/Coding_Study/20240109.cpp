#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//홀수 vs 짝수
int case1(vector<int> num_list) {
    int answer = 0;

    int odd = 0;
    int even = 0;

    for (int i = 0; i < num_list.size(); i++) {
        if (i % 2 == 0) even += num_list[i];
        else odd += num_list[i];
    }


    return max(even, odd);
}

//5명씩
vector<string> case2(vector<string> names) {
    vector<string> answer;

    for (int i = 0; i < names.size(); i++) {
        if (i % 5 == 0) answer.push_back(names[i]);
    }

    return answer;
}

//할 일 목록
vector<string> case3(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;

    for (int i = 0; i < todo_list.size(); i++) {
        if (finished[i] == false) answer.push_back(todo_list[i]);
    }

    return answer;
}

//n보다 커질 때까지 더하기
int case4(vector<int> numbers, int n) {
    int answer = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (answer > n) break;
        answer += numbers[i];
    }

    return answer;
}

//수열과 구간 쿼리 1
vector<int> case5(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++) {
        for (int j = queries[i][0]; j <= queries[i][1]; j++) arr[j]++;
    }
    answer = arr;

    return answer;
}