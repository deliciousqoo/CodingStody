/*
* 프로그래머스 기능 개발
* 자료구조 - 큐
* 20240206
*/
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> complete(progresses.size(), 0.0f);
    queue<int> myQueue;

    for (int i = 0; i < progresses.size(); i++) {
        complete[i] = ceil((float)(100 - progresses[i]) / speeds[i]);
    }

    int count;
    myQueue.push(complete[0]);
    for (int i = 1; i < complete.size(); i++) {
        if (myQueue.front() < complete[i]) {
            count = 0;
            while (!myQueue.empty()) {
                myQueue.pop();
                count++;
            }
            myQueue.push(complete[i]);
            answer.push_back(count);
        }
        else {
            myQueue.push(complete[i]);
        }
    }
    answer.push_back(myQueue.size());


    return answer;
}