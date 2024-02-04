#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//문자열의 앞의 n글자
string case1(string my_string, int n) {
    string answer = "";

    answer = my_string.substr(0, n);

    return answer;
}

//접두사인지 확인하기
int case2(string my_string, string is_prefix) {
    int answer = 0;
    vector<string> temp_arr;

    for (int i = 1; i <= my_string.length(); i++) {
        temp_arr.push_back(my_string.substr(0, i));
    }

    for (int i = 0; i < temp_arr.size(); i++) {
        if (is_prefix.compare(temp_arr[i]) == 0) answer = 1;
    }

    return answer;
}

//문자열 뒤집기
string case3(string my_string, int s, int e) {
    string answer = "";

    for (int i = 0; i < e - s + 1; i++) answer.push_back(my_string[e - i]);
    my_string.replace(s, e - s + 1, answer);
    answer = my_string;

    return answer;
}

//세로 읽기
string case4(string my_string, int m, int c) {
    string answer = "";

    int temp = 0;
    int index = 0;
    while (index < my_string.length()) {
        if (index == (c - 1) + (m * temp)) {
            answer.push_back(my_string[index]);
            temp++;
        }
        index++;
    }

    return answer;
}

//qr code
string case5(int q, int r, string code) {
    string answer = "";

    for (int i = 0; i < code.length(); i++) {
        if (i % q == r) answer.push_back(code[i]);
    }

    return answer;
}