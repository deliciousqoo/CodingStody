#include <string>
#include <vector>

using namespace std;

//���ڿ� ����
string case1(string str1, string str2) {
    string answer = "";
    for (int i = 0; i < str1.size(); i++) {
        answer.push_back(str1[i]);
        answer.push_back(str2[i]);
    }
    return answer;
}

//���� ����Ʈ�� ���ڿ��� ��ȯ�ϱ�
string case2(vector<string> arr) {
    string answer = "";
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    return answer;
}

//���ڿ� ���ϱ�
string case3(string my_string, int k) {
    string answer = "";
    for (int i = 0; i < k; i++) {
        answer += my_string;
    }
    return answer;
}

//�� ũ�� ��ġ��
int case4(int a, int b) {
    int answer = 0;

    string temp1 = "";
    string temp2 = "";

    temp1 = to_string(a) + to_string(b);
    temp2 = to_string(b) + to_string(a);

    if (stoi(temp1) >= stoi(temp2)) {
        answer = stoi(temp1);
    }
    else {
        answer = stoi(temp2);
    }

    return answer;
}

//�� ���� ���갪 ���ϱ�
int case5(int a, int b) {
    int answer = 0;

    answer = max(2 * a * b, stoi(to_string(a) + to_string(b)));

    return answer;
}