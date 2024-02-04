#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//n ��° ���Һ���
vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;

    for (int i = n - 1; i < num_list.size(); i++) answer.push_back(num_list[i]);

    return answer;
}

//���� �ٲٱ�
vector<int> case2(vector<int> num_list, int n) {
    vector<int> answer;

    for (int i = 0; i < num_list.size(); i++) answer.push_back(num_list[(i + n) % num_list.size()]);

    return answer;
}

//���� ������
vector<string> case3(vector<string> str_list) {
    vector<string> answer;

    for (int i = 0; i < str_list.size(); i++) {
        if (str_list[i].compare("l") == 0) {
            for (int j = 0; j < i; j++) answer.push_back(str_list[j]);
            break;
        }
        else if (str_list[i].compare("r") == 0) {
            for (int j = i + 1; j < str_list.size(); j++) answer.push_back(str_list[j]);
            break;
        }
    }

    return answer;
}

//n ��° ���ұ���
vector<int> case4(vector<int> num_list, int n) {
    vector<int> answer;

    for (int i = 0; i < n; i++) answer.push_back(num_list[i]);

    return answer;
}

//n�� ������ ���ҵ�
vector<int> case5(vector<int> num_list, int n) {
    vector<int> answer;

    for (int i = 0; i < num_list.size(); i += n) answer.push_back(num_list[i]);

    return answer;
}