#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string a;
    int len = s.length();
    int word_length = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i]!=32)//공백문자가 아니라면
        {
            if (word_length % 2 == 0)//짝수->대문자
            {
                if (s[i] > 96)
                    s[i] = s[i] - 32;
                word_length++;
            }
            else  //홀수->소문자
            {
                if (s[i] < 91)//대문자라면
                    s[i] = s[i] + 32;
                word_length++;
            }
        }
        else//공백인경우
        {
            word_length = 0;
        }
    }
    return s;
}

int main(void)
{
    string a = "Hello World dsvKCKCMlkCMkmd";
    cout << solution(a)<<endl;
}