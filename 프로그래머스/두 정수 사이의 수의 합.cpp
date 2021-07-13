#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int max, min = 0;
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        min = a;
        max = b;
    }
    for (; min <= max; min++)
    {
        answer += min;
    }
    return answer;
}
int main(void)
{
    cout << solution(21, 17);
}