#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool is_digit_char(char c)
{
    return ('0' <= c && c <= '9');
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> sub;
    string tmp="";
    for (int i = 0; i < s.size(); )
    {
        tmp = "";
        if (is_digit_char(s[i]) == 0)
        {
            i++;
            continue;
        }
        while (is_digit_char(s[i])) {
            tmp.append(s.substr(i, 1));
            i++;
        }
        answer.push_back(stoi(tmp));
        sub.push_back(stoi(tmp)); 
    }
    sort(sub.begin(), sub.end());
    sub.erase(unique(sub.begin(), sub.end()), sub.end()); //원소들 값 복수 제거하여 저장
    vector <int> value(sub.size());
    for (int i = 0; i < sub.size(); i++)
    {
        int c =count(answer.begin(), answer.end(),sub[i]);
        value[sub.size()-c] = sub[i];
    }
    return value;
}
