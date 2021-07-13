#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    if (len == 4 || len == 6)
    {
        for (int i = 0; i < len; i++)
        {
            if (s[i] > 57 || s[i] < 48) //숫자가 아닌경우
            {
                answer = false;
                break;
            }
        }
    }
    else
    {
        answer = false;
    }
    return answer;
}
int main(void)
{
    cout << solution("5123");
}