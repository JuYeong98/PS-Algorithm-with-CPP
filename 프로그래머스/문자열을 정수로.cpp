#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    int decimal = 1;
    for (int i = 0; i < len; i++)
    {
        if (s[0] == '-')
        {
            if (i >= 1)
            {
                answer = answer + (s[i] - 48) * pow(10, len-i-1);
            }
        }
        else if (s[0] == '+')
        {
            if (i >= 1)
            {
                answer = answer + (s[i] - 48) * pow(10, len - i - 1);
            }
        }
        else
        {
            answer = answer+  (s[i] - 48) * pow(10, len-i-1);
        }
    }
    if (s[0] == '-')
        answer *= -1;
    return answer;
}
 
int main(void)
{
    cout << solution("+1234");
}