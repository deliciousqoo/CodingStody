#include <iostream>
#include <string>

using namespace std;

//덧셈식 출력하기
int case1(void) {
    int a;
    int b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b;
    return 0;
}

//문자열 붙여서 출력하기
int case2(void) {
    string str1, str2;
    cin >> str1 >> str2;
    cout << str1 + str2;
    return 0;
}

//문자열 돌리기
int case3(void) {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }
    return 0;
}

//홀짝 구분하기
int case4(void) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n << " is even";
    }
    else {
        cout << n << " is odd";
    }
    return 0;
}

//문자열 겹쳐쓰기
string case5(string my_string, string overwrite_string, int s) {
    string answer = "";

    int count = 0;
    for (int i = 0; i < my_string.size(); i++) {
        if (i >= s && i <= s + overwrite_string.size() - 1) {
            my_string[i] = overwrite_string[count++];
        }
    }
    answer = my_string;

    return answer;
}