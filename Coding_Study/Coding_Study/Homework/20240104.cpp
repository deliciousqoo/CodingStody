#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//배열 만들기 5
vector<int> case1(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    string temp_str;
    int temp_ans;

    for (int i = 0; i < intStrs.size(); i++) {
        temp_str = "";
        temp_ans = stoi(intStrs[i].substr(s, l));
        if (temp_ans > k) answer.push_back(temp_ans);
    }
    return answer;
}

//부분 문자열 이어 붙여 문자열 만들기
string case2(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";

    for (int i = 0; i < my_strings.size(); i++) { answer.append(my_strings[i].substr(parts[i][0], parts[i][1] - parts[i][0] + 1)); }

    return answer;
}

//문자열의 뒤의 n글자
string case3(string my_string, int n) {
    string answer = "";

    answer = my_string.substr(my_string.length() - n, n);

    return answer;
}

//접미사 배열
vector<string> case4(string my_string) {
    vector<string> answer;

    for (int i = my_string.length() - 1; i >= 0; i--) { answer.push_back(my_string.substr(i)); }
    sort(answer.begin(), answer.end());

    return answer;
}

//접미사인지 확인하기
int case5(string my_string, string is_suffix) {
    int answer = 0;
    vector<string> temp_arr;

    for (int i = my_string.length() - 1; i >= 0; i--) temp_arr.push_back(my_string.substr(i));
    for (int i = 0; i < temp_arr.size(); i++) if (temp_arr[i].compare(is_suffix) == 0) answer++;

    return answer;
}