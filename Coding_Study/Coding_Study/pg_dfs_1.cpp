#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int depth, int sum) {
    if (depth == numbers.size() - 1) {
        if (sum == target) answer++;
        return;
    }

    DFS(numbers, target, depth + 1, sum + numbers[depth + 1]);
    DFS(numbers, target, depth + 1, sum - numbers[depth + 1]);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, numbers[0]);
    DFS(numbers, target, 0, -numbers[0]);

    return answer;
}