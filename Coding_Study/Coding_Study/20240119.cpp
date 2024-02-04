#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0 떼기
string case1(string n_str) {
    string answer = "";

    bool check = false;
    for (int i = 0; i < n_str.length(); i++) {
        if (n_str[i] != '0') { check = true; }
        if (check) { answer.push_back(n_str[i]); }
    }

    return answer;
}

// 두 수의 합
string temp_ans = "";

string case2(string a, string b) {
    string answer = "0";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) { a.resize(b.size(), '0'); }
    else { b.resize(a.size(), '0'); }

    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        int temp = (a[i] - '0') + (b[i] - '0') + count;
        count = temp / 10;
        temp %= 10;
        answer.push_back(temp + '0');
    }
    if (count != 0) answer += to_string(count);
    reverse(answer.begin(), answer.end());
    answer.pop_back();

    return answer;
}

// 문자열로 변환
string case3(int n) {
    string answer = "";

    answer = to_string(n);

    return answer;
}

// 배열의 원소 삭제하기
vector<int> case4(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < delete_list.size(); j++) {
            if (arr[i] == delete_list[j]) {
                arr.erase(arr.begin() + i);
                i -= 1;
            }
        }
    }
    answer = arr;

    return answer;
}

// 부분 문자열인지 확인하기
int case5(string my_string, string target) {
    int answer = 0;

    if (my_string.find(target) != string::npos) {
        answer = 1;
    }

    return answer;
}