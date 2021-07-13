#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_num = 0;
    int y_num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 80 || s[i] == 112)
        {
            p_num++;
        }
        if (s[i] == 89 || s[i] == 121)
        {
            y_num++;
        }
    }
    if (p_num == y_num)
        answer = true;
    else
        answer = false;

    return answer;
}
int main(void)
{

}