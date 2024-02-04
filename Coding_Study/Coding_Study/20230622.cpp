#include <string>
#include <vector>

using namespace std;

//n의 배수
int case1(int num, int n) {
    int answer = 0;

    if (num % n == 0) {
        answer = 1;
    }
    else {
        answer = 0;
    }

    return answer;
}

//공배수
int case2(int number, int n, int m) {
    int answer = 0;

    if (number % n == 0 && number % m == 0) {
        answer = 1;
    }
    else answer = 0;

    return answer;
}

//홀짝에 따라 다른 값 변환하기
int case3(int n) {
    int answer = 0;

    for (int i = 0; i <= n; i++) {
        if (n % 2 == 0 && i % 2 == 0) {
            answer += pow(i, 2);
        }
        else if (n % 2 == 1 && i % 2 == 1) {
            answer += i;
        }
    }

    return answer;
}

//조건 문자열
int case4(string ineq, string eq, int n, int m) {
    int answer = 0;
    string temp = "";
    temp = ineq + eq;

    if (temp == ">=") {
        if (n >= m) answer = 1;
    }
    else if (temp == "<=") {
        if (n <= m) answer = 1;
    }
    else if (temp == ">!") {
        if (n > m) answer = 1;
    }
    else if (temp == "<!") {
        if (n < m) answer = 1;
    }

    return answer;
}

//flag에 따라 다른 값 반환하기
int case5(int a, int b, bool flag) {
    int answer = 0;
    if (flag) {
        answer = a + b;
    }
    else {
        answer = a - b;
    }
    return answer;
}