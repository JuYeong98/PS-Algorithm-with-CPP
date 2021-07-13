#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    int len = phone_number.length();
    for (int i = 0; i < len - 4; i++)
    {
        answer[i] = '*';
    }
   
    return answer;
}
int main(void)
{
    cout << solution("01066357192");
}