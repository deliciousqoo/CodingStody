#include <string>
#include <vector>

using namespace std;

//간단한 논리 연산
bool case1(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    answer = (x1 || x2) && (x3 || x4);
    return answer;
}

//주사위 게임 3 
int case2(int a, int b, int c, int d) {
    int answer = 0;
    int arr[7] = { 0, };
    int p = 0, q = 0, r = 0;

    arr[a]++;
    arr[b]++;
    arr[c]++;
    arr[d]++;

    int temp = 1;
    int count = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        if (arr[i] != 0) {
            temp *= arr[i];
            count++;
        }
    }

    if (temp == 4) {
        if (count == 1) answer = 1111 * a;
        else {
            for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
                if (arr[i] == 2) {
                    if (p == 0) p = i;
                    else q = i;
                }
            }
            answer = (p + q) * abs(p - q);
        }
    }
    else if (temp == 3) {
        for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
            if (arr[i] == 3) p = i;
            else if (arr[i] == 1) q = i;
        }
        answer = pow((10 * p + q), 2);
    }
    else if (temp == 2) {
        for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
            if (arr[i] == 1) {
                if (q == 0) q = i;
                else r = i;
            }
        }
        answer = q * r;
    }
    else if (temp == 1) {
        answer = min(a, min(b, min(c, d)));
    }

    return answer;
}

//글자 이어 붙여 문자열 만들기
string case3(string my_string, vector<int> index_list) {
    string answer = "";

    for (int i = 0; i < index_list.size(); i++) answer.push_back(my_string[index_list[i]]);

    return answer;
}

//9로 나눈 나머지
int case4(string number) {
    int answer = 0;

    for (int i = 0; i < number.length(); i++) {
        answer += number[i] - '0';
    }
    answer = answer % 9;

    return answer;
}

//문자열 여러 번 뒤집기
string case5(string my_string, vector<vector<int>> queries) {
    string answer = "";
    string temp;

    for (int i = 0; i < queries.size(); i++) {
        temp = "";
        for (int j = queries[i][1]; j >= queries[i][0]; j--) temp.push_back(my_string[j]);
        my_string.replace(queries[i][0], queries[i][1] - queries[i][0] + 1, temp);
    }

    return my_string;
}