#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�빮�ڷ� �ٲٱ�
string case1(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        myString[i] = toupper(myString[i]);
    }
    answer = myString;

    return answer;
}

//�ҹ��ڷ� �ٲٱ�
string case2(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        myString[i] = tolower(myString[i]);
    }
    answer = myString;

    return answer;
}

//�迭���� ���ڿ� ��ҹ��� ��ȯ�ϱ�
vector<string> case3(vector<string> strArr) {
    vector<string> answer;

    for (int i = 0; i < strArr.size(); i++) {
        for (int j = 0; j < strArr[i].length(); j++) {
            if (i % 2 == 0) {
                strArr[i][j] = tolower(strArr[i][j]);
            }
            else {
                strArr[i][j] = toupper(strArr[i][j]);
            }
        }
    }
    answer = strArr;

    return answer;
}

//A �����ϱ�
string case4(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'a') myString[i] = toupper(myString[i]);
        else if (myString[i] < 'a' && myString[i] != 'A') myString[i] = tolower(myString[i]);
    }
    answer = myString;

    return answer;
}

//Ư���� ���ڸ� �빮�ڷ� �ٲٱ�
string case5(string my_string, string alp) {
    string answer = "";

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] == alp[0]) my_string[i] = toupper(my_string[i]);
    }
    answer = my_string;

    return answer;
}