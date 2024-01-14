#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//x ������ ����
vector<int> case1(string myString) {
    vector<int> answer;

    int count = 0;
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'x') {
            answer.push_back(count);
            count = 0;
        }
        else {
            count++;
        }
    }
    answer.push_back(count);

    return answer;
}

//���ڿ� �߶� �����ϱ�
vector<string> case2(string myString) {
    vector<string> answer;

    string temp = "";
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'x') {
            if (temp.length() > 0) {
                answer.push_back(temp);
                temp = "";
            }
        }
        else {
            temp.push_back(myString[i]);
        }
    }
    if (temp.length() > 0) {
        answer.push_back(temp);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

//������ �� ����ϱ�
int case3(string binomial) {
    int answer = 0;

    int a_end, b_begin;
    string a_temp, b_temp;
    for (int i = 0; i < binomial.length(); i++) {
        if (binomial[i] == '+' || binomial[i] == '-' || binomial[i] == '*') {
            a_end = i - 2;
            b_begin = i + 2;
            for (int j = 0; j <= a_end; j++) { a_temp.push_back((char)binomial[j]); }
            for (int j = b_begin; j <= binomial.length(); j++) { b_temp.push_back((char)binomial[j]); }
            switch (binomial[i]) {
            case '+':
                answer = stoi(a_temp) + stoi(b_temp);
                break;
            case '-':
                answer = stoi(a_temp) - stoi(b_temp);
                break;
            case '*':
                answer = stoi(a_temp) * stoi(b_temp);
                break;
            }
        }
    }


    return answer;
}

//���ڿ� �ٲ㼭 ã��
int case4(string myString, string pat) {
    int answer = 0;

    string temp = "";
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'A') { temp.push_back('B'); }
        else if (myString[i] == 'B') { temp.push_back('A'); }
    }

    if (temp.find(pat) != string::npos) answer = 1;

    return answer;
}

//rny_string
string case5(string rny_string) {
    string answer = "";

    for (int i = 0; i < rny_string.length(); i++) {
        if (rny_string[i] == 'm') {
            answer.append("rn");
        }
        else {
            answer.push_back(rny_string[i]);
        }
    }

    return answer;
}

//�� ���� ������
vector<string> case6(string myString) {
    vector<string> answer;

    string temp = "";
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'a' || myString[i] == 'b' || myString[i] == 'c') {
            if (temp.length() > 0) {
                answer.push_back(temp);
                temp = "";
            }
        }
        else {
            temp.push_back(myString[i]);
        }
    }
    if (temp.length() > 0) {
        answer.push_back(temp);
    }

    if (answer.size() == 0) answer.push_back("EMPTY");

    return answer;
}

//�迭�� ���Ҹ�ŭ �߰��ϱ�
vector<int> case7(vector<int> arr) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i]; j++) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

//�� �迭�� �߰�, �����ϱ�
vector<int> case8(vector<int> arr, vector<bool> flag) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (flag[i]) {
            for (int j = 0; j < arr[i] * 2; j++) {
                answer.push_back(arr[i]);
            }
        }
        else {
            for (int j = 0; j < arr[i]; j++) {
                answer.pop_back();
            }
        }
    }

    return answer;
}

//�迭 ����� 6
vector<int> case9(vector<int> arr) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (answer.size() == 0) { answer.push_back(arr[i]); }
        else if (answer[answer.size() - 1] == arr[i]) { answer.pop_back(); }
        else { answer.push_back(arr[i]); }
    }

    if (answer.size() == 0) { answer.push_back(-1); }

    return answer;
}

//�������� k���� �� �̱�
vector<int> case10(vector<int> arr, int k) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (answer.size() == k) break;
        if (find(answer.begin(), answer.end(), arr[i]) == answer.end()) {
            answer.push_back(arr[i]);
        }
    }

    int ans_size = answer.size();
    if (answer.size() < k) {
        for (int i = 0; i < k - ans_size; i++) {
            answer.push_back(-1);
        }
    }

    return answer;
}