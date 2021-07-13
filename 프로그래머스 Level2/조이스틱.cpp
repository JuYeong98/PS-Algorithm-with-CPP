#include <string>
#include <vector>
#include <iostream>
using namespace std;
int change_alpha(char c);
int solution(string name) {
    int answer = 0;

    vector <int> a;
    for (int i = 0; i < name.size(); i++)
    {
        a.push_back(change_alpha(name[i]));
        answer += change_alpha(name[i]);
    }
    int count1 = 1;
    int count2 = a.size() - 1;
    if (a[count1] != 0 && a[count2] != 0)
    {
        answer += count2;
        return answer;
    }
    while (a[count1] == 0)
        count1++;
    while (a[count2] == 0)
        count2--;
    
    if (count1 - 1 <= a.size() - 1 - count2)//정상 순회
    {
        answer += a.size() - 1 - count2;
    }
    else {//거꾸로 순회
        answer += a.size() - count1;
    }
    return answer;
}
int change_alpha(char c)
{
    int result = 0;
    if (c <= 78)
    {
        result = c - 'A';
    }
    else if (c > 78)
    {
        result = 'Z' - c;
        result++;
    }
    return result;
}
