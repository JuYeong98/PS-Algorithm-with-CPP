#include <iostream>
#include<string>
using namespace std;

string remove_same(string s)
{
    string tmp = "";
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            tmp = s.substr(0, i);
            tmp += s.substr(i + 2);
            return tmp;
        }
    }
    
}
int is_able_remove(string s)
{
    if (s.size() % 2 == 1)
        return 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1])//하나라도 지울 게 있으면 true
            return 1;
    }
    return 0;  //지울게 없는 경우
}

int solution(string s)
{
    if (s.size() % 2 == 1)
        return 0;
    while (1){
       //cout << s << "  ";
        string tmp = "";
        if (s == "")
            return 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (s.size() == 2)
                    return 1;
                tmp = s.substr(0, i);
                tmp += s.substr(i + 2);
                s = tmp;
                cout << s;
                continue;
            }
            if (i == s.size() - 2)
                return 0;
        }
    }
}
int main(void)
{
    cout<<solution("baabaa");
   // cout << remove_same("baabaa");
}