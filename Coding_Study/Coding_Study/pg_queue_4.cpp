/*
* 프로그래머스 프로세스
* 자료구조 - 큐
* 20240206
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> edge;


int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<edge> myQueue;
    vector<queue<edge>> arr(10);

    for (int i = 0; i < priorities.size(); i++) {
        myQueue.push(make_pair(i, priorities[i]));
    }

    while (!myQueue.empty()) {
        edge temp = myQueue.front();
        myQueue.pop();
        arr[temp.second].push(temp);

        for (int i = temp.second - 1; i > 0; i--) {
            if (arr[i].size() != 0) {
                while (!arr[i].empty()) {
                    myQueue.push(arr[i].front());
                    arr[i].pop();
                }
            }
        }
    }

    for (int i = 9; i > 0; i--) {
        if (arr[i].size() != 0) {
            while (!arr[i].empty()) {
                myQueue.push(arr[i].front());
                arr[i].pop();
            }
        }
    }

    int index = 1;
    while (!myQueue.empty()) {
        if (myQueue.front().first == location) answer = index;
        myQueue.pop();
        index++;
    }

    return answer;
}