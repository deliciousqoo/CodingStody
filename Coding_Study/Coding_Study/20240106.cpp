#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//���� ���� ����
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

//�迭 ����� 1
vector<int> case2(int n, int k) {
    vector<int> answer;

    for (int i = 1; i <= n; i++) if (i % k == 0) answer.push_back(i);

    return answer;
}

//���� �����
string case3(string my_string, vector<int> indices) {
    string answer = "";

    for (int i = 0; i < indices.size(); i++) my_string.replace(indices[i], 1, " ");
    for (int i = 0; i < my_string.length(); i++) if (my_string[i] >= 'A') answer.push_back(my_string[i]);

    return answer;
}

//ī��Ʈ �ٿ�
vector<int> case4(int start, int end_num) {
    vector<int> answer;

    for (int i = start; i >= end_num; i--) answer.push_back(i);

    return answer;
}

//����� 1 ã��
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