/*
<<<<<<< Updated upstream
* 프로그래머스 K번째수
* 정렬
* 20240215
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> temp;
    for (int i = 0; i < commands.size(); i++) {
        temp.clear();

        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());

        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
=======
* 프로그래머스 가장 큰 수
* 정렬, DFS
* 20240219
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> visited;
string max_value;

/*
void DFS(vector<int> arr, string temp, int now, int depth) {
	if (depth == arr.size()-1) {
		if (max_value == "") {
			max_value = temp;
		}
		else {
			if (temp > max_value) {
				max_value = temp;
			}
		}
		return;
	}
	if (visited[now]) return;
	visited[now] = true;

	for (int i = 0; i < arr.size(); i++) {
		if (!visited[i]) {
			DFS(arr, temp + to_string(arr[i]), i, depth + 1);
			visited[i] = false;
		}
	}
}*/

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

int main() {
	vector<int> numbers = { 0, 0, 0 };
	string answer = "";

	/*
	visited.resize(numbers.size(), false);

	max_value = "";
	for (int i = 0; i < numbers.size(); i++) {
		fill(visited.begin(), visited.end(), false);
		DFS(numbers, to_string(numbers[i]), i, 0);
	}*/

	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		if (answer.size() == 0 && numbers[i] == 0) continue;
		answer.append(to_string(numbers[i]));
	}
	if (answer.size() == 0) answer = "0";

	cout << answer;

	return 0;
>>>>>>> Stashed changes
}