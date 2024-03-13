/*
* ���α׷��ӽ� "�ڿ��� n ���� �̷���� �ߺ� ���� .. �ְ��� ����"
* 
* 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int sum = 0;
    int divide = n;
    vector<int> temp;

    while (n > 0 && s / n != 0) {
        answer.push_back((int)s / n);
        s -= s / n;
        n -= 1;
    }

    if (answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());

    return answer;
}