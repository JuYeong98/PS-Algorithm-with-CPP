#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool is_number(char c)
{
    return ('0' <= c && c <= '9');
}
char change_alpha1(char c)//�ҹ��ڷ�
{
    if (65 <= c && c <= 90)
        c = c + 32;
    return c;
}
char change_alpha2(char c)//�빮�ڷ�
{
    if (97 <= c && c <= 122)
        c = c - 32;
    return c;
}
string solution(string s) {
    string answer = "";
    bool buffer = false;
    if (is_number(s[0])) {//ù��° ���ڰ� ���ڶ��
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' ') {
                buffer = true;//��ĭ�̶��
                continue;
            }
            if (buffer == true) {
                char c = change_alpha2(s[i]);
                s[i] = c; buffer = false;
            }
            else if (buffer == false) {
                char c = change_alpha1(s[i]);
                s[i] = c;
            }
        }
    }
    else
    {   
        if (s[0] <= 'z' && s[0] >= 'a')
        {
            s[0] = s[0] - 32;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' '){
                buffer = true;//��ĭ�̶��
                continue;
            }
            if (buffer == true) {
                char c = change_alpha2(s[i]);
                s[i] = c; buffer = false;
            }
            else if(buffer == false) {
                char c = change_alpha1(s[i]);
                s[i] = c;
            }
        }
    }
    return s;
}

