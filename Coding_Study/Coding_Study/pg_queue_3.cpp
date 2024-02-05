/*
* 프로그래머스 올바른 괄호
* 자료구조 - 큐
* 20240206
*/
#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    queue<char> myQueue;
    myQueue.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '(') {
            myQueue.push(s[i]);
        }
        else {
            if (myQueue.front() == '(') {
                myQueue.pop();
            }
            else {
                myQueue.push(s[i]);
            }
        }
    }

    if (myQueue.size() != 0) answer = false;

    return answer;
}