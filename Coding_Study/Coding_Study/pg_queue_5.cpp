/*
* 프로그래머스 다리를 지나는 트럭
* 자료구조 - 큐
* 20240207
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    vector<int> count(truck_weights.size(), 0);
    queue<int> myQueue;

    int total_weight = 0;
    int pop_count = 0;
    int index = 0;
    while (pop_count < truck_weights.size()) {
        if (index < truck_weights.size()) {
            if (total_weight + truck_weights[index] <= weight) {
                total_weight += truck_weights[index];
                myQueue.push(index);
                index++;
            }
        }

        for (int i = myQueue.front(); i < index; i++) {
            count[i]++;
            if (count[myQueue.front()] >= bridge_length) {
                total_weight -= truck_weights[myQueue.front()];
                myQueue.pop();
                pop_count++;
            }
        }

        answer++;
    }

    return answer + 1;
}