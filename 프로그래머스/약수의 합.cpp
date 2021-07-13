#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            answer += i;
    }
    return answer;
}
int main(void)
{
    cout << solution(12);
}