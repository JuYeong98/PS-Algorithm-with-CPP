#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double a;
    a = sqrt(n);
    if (a == (int)a)
    {
        a++;
        answer = a * a;
    }
    else
    {
        answer = -1;
    }
    return answer;
}
int main(void)
{
    cout << solution(121);
}