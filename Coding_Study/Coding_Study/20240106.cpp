#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//문자 개수 세기
vector<int> case1(string my_string) {
    vector<int> answer;

    //for(int i=0;i<52;i++) answer.push_back(0);
    answer.reserve(52);

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] >= 'a') answer[my_string[i] - 71]++;
        else answer[my_string[i] - 65]++;
    }

    return answer;
}

//배열 만들기 1
vector<int> case2(int n, int k) {
    vector<int> answer;

    for (int i = 1; i <= n; i++) if (i % k == 0) answer.push_back(i);

    return answer;
}

//글자 지우기
string case3(string my_string, vector<int> indices) {
    string answer = "";

    for (int i = 0; i < indices.size(); i++) my_string.replace(indices[i], 1, " ");
    for (int i = 0; i < my_string.length(); i++) if (my_string[i] >= 'A') answer.push_back(my_string[i]);

    return answer;
}

//카운트 다운
vector<int> case4(int start, int end_num) {
    vector<int> answer;

    for (int i = start; i >= end_num; i--) answer.push_back(i);

    return answer;
}

//가까운 1 찾기
int case5(vector<int> arr, int idx) {
    int answer = -1;

    for (int i = idx; i < arr.size(); i++) {
        if (arr[i] == 1) {
            answer = i;
            break;
        }
    }

    return answer;
}