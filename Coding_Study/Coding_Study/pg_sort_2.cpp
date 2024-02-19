/*
* 프로그래머스 가장 큰 수
* 정렬
* 20240219
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
string max_value;

bool cmp(int n1, int n2) {
    string temp1 = to_string(n1);
    string temp2 = to_string(n2);
    if (stoi(temp1 + temp2) > stoi(temp2 + temp1)) {
        return true;
    }
    else
    {
        return false;
    }
}


string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);
    for (int i = 0; i < numbers.size(); i++) {
        if (answer.size() == 0 && numbers[i] == 0) continue;
        answer.append(to_string(numbers[i]));
    }
    if (answer.size() == 0) answer = "0";

    return answer;
}