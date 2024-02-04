#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//배열의 길이를 2의 거듭제곱으로 만들기
vector<int> case1(vector<int> arr) {
    vector<int> answer;

    int temp = 1;
    while (temp < arr.size()) {
        temp *= 2;
    }

    for (int i = 0; i < temp; i++) {
        if (i > arr.size() - 1) {
            answer.push_back(0);
        }
        else {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

//배열 비교하기
int case2(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    int temp1 = 0;
    int temp2 = 0;

    if (arr1.size() > arr2.size()) { answer = 1; }
    else if (arr1.size() < arr2.size()) { answer = -1; }
    else {
        for (int i = 0; i < arr1.size(); i++) { temp1 += arr1[i]; }
        for (int i = 0; i < arr2.size(); i++) { temp2 += arr2[i]; }
        if (temp1 > temp2) { answer = 1; }
        else if (temp1 < temp2) { answer = -1; }
        else { answer = 0; }
    }

    return answer;
}

//문자열 묶기
int arr[100001] = { 0 };

int case3(vector<string> strArr) {
    int answer = -1;

    for (int i = 0; i < strArr.size(); i++) {
        arr[strArr[i].length()]++;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        if (arr[i] > answer) answer = arr[i];
    }

    return answer;
}

//배열의 길이에 따라 다른 연산하기
vector<int> case4(vector<int> arr, int n) {
    vector<int> answer;

    if (arr.size() % 2 == 0) {
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 1) { arr[i] += n; }
        }
    }
    else {
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) { arr[i] += n; }
        }
    }
    answer = arr;

    return answer;
}

//뒤에서 5등까지
vector<int> case5(vector<int> num_list) {
    vector<int> answer;

    sort(num_list.begin(), num_list.end());
    for (int i = 0; i < 5; i++) answer.push_back(num_list[i]);

    return answer;
}