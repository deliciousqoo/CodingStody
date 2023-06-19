#include <iostream>
#include <string>

using namespace std;

//문자열 출력하기
int case1(void) {
    string str;
    cin >> str;
    cout << str;
    return 0;
}

//a와 b 출력하기
int case2(void) {
    int a;
    int b;
    cin >> a >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}

//문자열 반복해서 출력하기
int case3(void) {
    string str;
    int n;
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        cout << str;
    }
    return 0;
}

//대소문자 바꿔서 출력하기
int case4(void) {
    string str, temp;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a') {
            temp = toupper(str[i]);
            cout << temp;
        }
        else
        {
            temp = tolower(str[i]);
            cout << temp;
        }
    }
    return 0;
}

//특수문자 출력하기
int main(void) {
    cout << "!@#$%^&*(\\'\"<>?:;";
    return 0;
}