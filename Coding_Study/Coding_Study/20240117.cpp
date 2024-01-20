#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//뒤에서 5등 위로
vector<int> case1(vector<int> num_list) {
    vector<int> answer;

    sort(num_list.begin(), num_list.end());
    for (int i = 5; i < num_list.size(); i++) {
        answer.push_back(num_list[i]);
    }

    return answer;
}

//전국 대회 선발 고사
int case2(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pair<int, int>> temp;
    for (int i = 0; i < rank.size(); i++) {
        if (attendance[i]) {
            temp.push_back(make_pair(rank[i], i));
        }
    }
    sort(temp.begin(), temp.end());
    answer = 10000 * temp[0].second + 100 * temp[1].second + temp[2].second;

    return answer;
}

//정수 부분
int case3(double flo) {
    int answer = 0;

    answer = flo / 1;

    return answer;
}

//문자열 정수의 합
int case4(string num_str) {
    int answer = 0;

    for (int i = 0; i < num_str.length(); i++) {
        answer += num_str[i] - '0';
    }

    return answer;
}

//문자열을 정수로 변환하기
int case5(string n_str) {
    int answer = 0;

    answer = stoi(n_str);

    return answer;
}