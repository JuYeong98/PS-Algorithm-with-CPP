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
        if (s[i]!=32)//���鹮�ڰ� �ƴ϶��
        {
            if (word_length % 2 == 0)//¦��->�빮��
            {
                if (s[i] > 96)
                    s[i] = s[i] - 32;
                word_length++;
            }
            else  //Ȧ��->�ҹ���
            {
                if (s[i] < 91)//�빮�ڶ��
                    s[i] = s[i] + 32;
                word_length++;
            }
        }
        else//�����ΰ��
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