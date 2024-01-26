#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<int> test1;
vector<int> test2;

int main() {

	int N;
	time_t start, end;
	double result_1, result_2;

	cin >> N;

	start = clock();
	test2.resize(N + 1);0
	fill(test2.begin(), test2.end(), 0);
	end = clock();

	result_2 = (double)(end - start);

	start = clock();
	test1.resize(N + 1, 0);
	end = clock();

	result_1 = (double)(end - start);

	cout << "Resize 수행 시간 : " << result_1 << endl;
	cout << "Fill 수행 시간 : " << result_2 << endl;


	return 0;
}