#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//���ǿ� �°� ���� ��ȯ�ϱ� 1
vector<int> case1(vector<int> arr) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 50 && arr[i] % 2 == 0) arr[i] = arr[i] / 2;
        else if (arr[i] < 50 && arr[i] % 2 == 1) arr[i] = arr[i] * 2;
    }
    answer = arr;

    return answer;
}

//���ǿ� �°� ���� ��ȯ�ϱ� 2
int case2(vector<int> arr) {
    int answer = 0;
    int count = 0;

    while (count != arr.size()) {
        count = 0;
        answer++;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= 50 && arr[i] % 2 == 0) arr[i] = arr[i] / 2;
            else if (arr[i] < 50 && arr[i] % 2 == 1) arr[i] = arr[i] * 2 + 1;
            else count++;
        }
    }

    return answer - 1;
}

//1�� �����
int case3(vector<int> num_list) {
    int answer = 0;

    for (int i = 0; i < num_list.size(); i++) {
        while (num_list[i] != 1) {
            if (num_list[i] % 2 == 0) num_list[i] = num_list[i] / 2;
            else num_list[i] = (num_list[i] - 1) / 2;
            answer++;
        }
    }

    return answer;
}

//���̿� ���� ����
int case4(vector<int> num_list) {
    int answer = 0;

    if (num_list.size() >= 11) {
        for (int i = 0; i < num_list.size(); i++) answer += num_list[i];
    }
    else {
        answer = 1;
        for (int i = 0; i < num_list.size(); i++) answer *= num_list[i];
    }

    return answer;
}

//���ϴ� ���ڿ� ã��
int case5(string myString, string pat) {
    int answer = 0;

    for (int i = 0; i < myString.length(); i++) myString[i] = tolower(myString[i]);
    for (int i = 0; i < pat.length(); i++) pat[i] = tolower(pat[i]);

    if (myString.find(pat) != string::npos) {
        answer = 1;
    }

    return answer;
}