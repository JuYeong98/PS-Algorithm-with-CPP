#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    for (; n >= 1; n = n / 10)
    {
        answer += n % 10;
    }
    return answer;
}
int main(void)
{
    cout<<solution(3141);
}