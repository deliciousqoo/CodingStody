#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 커피 심부름
int case1(vector<string> order) {
    int answer = 0;

    for (int i = 0; i < order.size(); i++) {
        if (order[i].find("americano") != string::npos) {
            answer += 4500;
        }
        else if (order[i].find("latte") != string::npos) {
            answer += 5000;
        }
        else {
            answer += 4500;
        }
    }

    return answer;
}

// 그림 확대
vector<string> case2(vector<string> picture, int k) {
    vector<string> answer;

    string temp = "";
    for (int i = 0; i < picture.size(); i++) {
        temp = "";
        for (int j = 0; j < picture[i].length(); j++) {
            for (int n = 0; n < k; n++) {
                temp.push_back(picture[i][j]);
            }
        }
        for (int m = 0; m < k; m++) {
            answer.push_back(temp);
        }
    }

    return answer;
}

// 조건에 맞게 수열 변환하기 3
vector<int> case3(vector<int> arr, int k) {
    vector<int> answer;

    if (k % 2 == 1) {
        for (int i = 0; i < arr.size(); i++) {
            answer.push_back(arr[i] * k);
        }
    }
    else {
        for (int i = 0; i < arr.size(); i++) {
            answer.push_back(arr[i] + k);
        }
    }

    return answer;
}

// I로 만들기
string case4(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] < 'l') {
            answer.push_back('l');
        }
        else {
            answer.push_back(myString[i]);
        }
    }

    return answer;
}

// 특별한 이차원 배열 1
vector<vector<int>> case5(int n) {
    vector<vector<int>> answer;

    answer.resize(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        answer[i].resize(n, 0);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                answer[i][j] = 1;
            }
            else {
                answer[i][j] = 0;
            }
        }
    }

    return answer;
}