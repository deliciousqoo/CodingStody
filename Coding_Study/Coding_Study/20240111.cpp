#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//대문자로 바꾸기
string case1(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        myString[i] = toupper(myString[i]);
    }
    answer = myString;

    return answer;
}

//소문자로 바꾸기
string case2(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        myString[i] = tolower(myString[i]);
    }
    answer = myString;

    return answer;
}

//배열에서 문자열 대소문자 변환하기
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

//A 강조하기
string case4(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'a') myString[i] = toupper(myString[i]);
        else if (myString[i] < 'a' && myString[i] != 'A') myString[i] = tolower(myString[i]);
    }
    answer = myString;

    return answer;
}

//특정한 문자를 대문자로 바꾸기
string case5(string my_string, string alp) {
    string answer = "";

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] == alp[0]) my_string[i] = toupper(my_string[i]);
    }
    answer = my_string;

    return answer;
}