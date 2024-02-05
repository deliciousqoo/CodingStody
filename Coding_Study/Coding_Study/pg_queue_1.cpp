/*
* ���α׷��ӽ� ���� ���ڴ� �Ⱦ�
* �ڷᱸ�� - ť
* 20240206
*/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> myQueue;

    myQueue.push(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (myQueue.back() != arr[i]) myQueue.push(arr[i]);
    }

    while (!myQueue.empty()) {
        answer.push_back(myQueue.front());
        myQueue.pop();
    }

    return answer;
}