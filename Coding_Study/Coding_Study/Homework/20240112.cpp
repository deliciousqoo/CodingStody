#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//특정 문자열로 끝나는 가장 긴 부분 문자열 찾기
int ans_int;

void case1_DFS(string myString, string pat, int max_length) {
    if (ans_int == max_length) return;

    if (myString.find(pat) != string::npos) {
        int temp = myString.find(pat);
        ans_int += temp + pat.length();
        case1_DFS(myString.substr(temp + pat.length(), myString.length() - 1), pat, max_length);
    }
    return;
}

string case1(string myString, string pat) {
    string answer = "";

    case1_DFS(myString, pat, myString.length());

    for (int i = 0; i < ans_int; i++) answer.push_back(myString[i]);

    return answer;
}

//문자열이 몇 번 등장하는지 세기
int ans_count = 0;

void case2_DFS(string myString, string pat) {
    if (myString.find(pat) != string::npos) {
        int temp = myString.find(pat);
        ans_count++;
        case2_DFS(myString.substr(temp + 1, myString.length() - 1), pat);
    }
    return;
}

int case2(string myString, string pat) {

    case2_DFS(myString, pat);

    return ans_count;
}

//ad 제거하기
vector<string> solution(vector<string> strArr) {
    vector<string> answer;

    for (int i = 0; i < strArr.size(); i++) {
        if (strArr[i].find("ad") == string::npos) {
            answer.push_back(strArr[i]);
        }
    }

    return answer;
}

//공백으로 구분하기 1
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> case4(string my_string) {
    vector<string> answer;

    answer = split(my_string, ' ');

    return answer;
}

//공백으로 구분하기 2
vector<string> case5(string my_string) {
    vector<string> answer;
    string temp = "";

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] != ' ') temp.push_back(my_string[i]);
        else {
            if (temp.length() > 0) {
                answer.push_back(temp);
                temp = "";
            }
        }
    }
    if (temp.length() > 0) {
        answer.push_back(temp);
        temp = "";
    }

    return answer;
}