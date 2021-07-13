#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    if (len % 2 == 0)
    {
        int mid = (len / 2) - 1;
        answer = s.substr(mid, 2);
    }
    else
    {
        int mid = len / 2;
        answer = s.substr(mid, 1);
    }
    return answer;
}

int main(void)
{
    string example = "abcde";
    string example2 = "qwer";
    cout << solution(example) << endl;
    cout << solution(example2) << endl;
}