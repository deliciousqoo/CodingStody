#include <iostream>
#include <string>

using namespace std;

//���ڿ� ����ϱ�
int case1(void) {
    string str;
    cin >> str;
    cout << str;
    return 0;
}

//a�� b ����ϱ�
int case2(void) {
    int a;
    int b;
    cin >> a >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}

//���ڿ� �ݺ��ؼ� ����ϱ�
int case3(void) {
    string str;
    int n;
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        cout << str;
    }
    return 0;
}

//��ҹ��� �ٲ㼭 ����ϱ�
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

//Ư������ ����ϱ�
int main(void) {
    cout << "!@#$%^&*(\\'\"<>?:;";
    return 0;
}