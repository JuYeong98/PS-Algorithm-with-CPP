#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    string a = "";
    string b = "";
    int len = s.length();
    for (int i = len-1; i >=0; i--)
    {
        for (int j = i; j >=0; j--)
        {
            if (s.at(i) > s.at(j))
            {
                a = s.at(i);
                b = s.at(j);
                s.replace(i, 1, b);
                s.replace(j, 1, a);
            }
        }
    }
    answer = s;

    return answer;
}

int main(void)
{
    string exam = "bOVvrvLwlcborLAfIBVsjn";
    cout << solution(exam) << endl;
    return 0;
}