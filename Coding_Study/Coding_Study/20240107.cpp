#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//리스트 자르기
vector<int> case1(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;

    switch (n) {
    case 1:
        for (int i = 0; i <= slicer[1]; i++) answer.push_back(num_list[i]);
        break;
    case 2:
        for (int i = slicer[0]; i < num_list.size(); i++) answer.push_back(num_list[i]);
        break;
    case 3:
        for (int i = slicer[0]; i <= slicer[1]; i++) answer.push_back(num_list[i]);
        break;
    case 4:
        for (int i = slicer[0]; i <= slicer[1]; i += slicer[2]) answer.push_back(num_list[i]);
        break;
    }

    return answer;
}

//첫 번째로 나오는 음수
int case2(vector<int> num_list) {
    int answer = -1;

    for (int i = 0; i < num_list.size(); i++) { if (num_list[i] < 0 && answer == -1) answer = i; }

    return answer;
}

//배열 만들기 3
vector<int> case3(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;

    for (int i = intervals[0][0]; i <= intervals[0][1]; i++) answer.push_back(arr[i]);
    for (int i = intervals[1][0]; i <= intervals[1][1]; i++) answer.push_back(arr[i]);

    return answer;
}

//2의 영역
vector<int> case4(vector<int> arr) {
    vector<int> answer;

    int first_index = -1;
    int last_index = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (first_index < 0 && arr[i] == 2) first_index = i;
        if (arr[i] == 2) last_index = i;
    }

    if (first_index == -1) answer.push_back(-1);
    else for (int i = first_index; i <= last_index; i++) answer.push_back(arr[i]);

    return answer;
}

//배열 조각하기
vector<int> case5(vector<int> arr, vector<int> query) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < query.size(); i++) {
        temp.clear();
        if (i % 2 == 0) {
            for (int j = 0; j <= query[i]; j++) temp.push_back(arr[j]);
        }
        else {
            for (int j = query[i]; j < arr.size(); j++) temp.push_back(arr[j]);
        }
        arr.clear();
        arr = temp;
    }
    answer = arr;

    return answer;
}