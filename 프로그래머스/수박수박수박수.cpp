#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    if (n % 2 == 0)
    {
        string watermelon = "����";
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            answer.append(watermelon);
        }
    }
    else
    {
        string watermelon = "����";
        string halfmelon = "��";
        int half = n / 2 ;
        for (int i = 0; i < half; i++)
        {
            answer.append(watermelon);
        }
        answer.append(halfmelon);
    }
    return answer;
}
int main(void)
{
    cout << solution(3) << endl;
    cout << solution(4) << endl;
}