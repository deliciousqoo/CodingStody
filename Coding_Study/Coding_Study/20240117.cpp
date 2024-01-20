#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�ڿ��� 5�� ����
vector<int> case1(vector<int> num_list) {
    vector<int> answer;

    sort(num_list.begin(), num_list.end());
    for (int i = 5; i < num_list.size(); i++) {
        answer.push_back(num_list[i]);
    }

    return answer;
}

//���� ��ȸ ���� ���
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

//���� �κ�
int case3(double flo) {
    int answer = 0;

    answer = flo / 1;

    return answer;
}

//���ڿ� ������ ��
int case4(string num_str) {
    int answer = 0;

    for (int i = 0; i < num_str.length(); i++) {
        answer += num_str[i] - '0';
    }

    return answer;
}

//���ڿ��� ������ ��ȯ�ϱ�
int case5(string n_str) {
    int answer = 0;

    answer = stoi(n_str);

    return answer;
}