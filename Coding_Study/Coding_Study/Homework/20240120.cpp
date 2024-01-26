#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 부분 문자열
int case1(string str1, string str2) {
    int answer = 0;

    if (str2.find(str1) != string::npos) {
        answer = 1;
    }

    return answer;
}

// 꼬리 문자열
string case2(vector<string> str_list, string ex) {
    string answer = "";

    for (int i = 0; i < str_list.size(); i++) {
        if (str_list[i].find(ex) == string::npos) {
            answer.append(str_list[i]);
        }
    }

    return answer;
}

// 정수 찾기
int case3(vector<int> num_list, int n) {
    int answer = 0;

    for (int i = 0; i < num_list.size(); i++) {
        if (num_list[i] == n) { answer = 1; }
    }

    return answer;
}

// 주사위 게임 1
int case4(int a, int b) {
    int answer = 0;

    if ((a + b) % 2 == 1) {
        answer = 2 * (a + b);
    }
    else {
        if ((a * b) % 2 == 1) {
            answer = pow(a, 2) + pow(b, 2);
        }
        else {
            answer = abs(a - b);
        }
    }

    return answer;
}

// 날짜 비교하기
int case5(vector<int> date1, vector<int> date2) {
    int answer = 0;

    if (date1[0] < date2[0]) { answer = 1; }
    else if (date1[0] == date2[0]) {
        if (date1[1] < date2[1]) { answer = 1; }
        else if (date1[1] == date2[1]) {
            if (date1[2] < date2[2]) { answer = 1; }
        }
        else { answer = 0; }
    }
    else { answer = 0; }

    return answer;
}