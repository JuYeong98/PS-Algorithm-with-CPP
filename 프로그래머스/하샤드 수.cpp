#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    bool answer = true;
    int x_copy = x;
    int sum_of_hashard=0;
    for (; x >= 1; x = x / 10)
    {
        int input = x % 10;
        sum_of_hashard += input;
    }     
    if (x_copy % sum_of_hashard == 0)
        answer = true;
    else
        answer = false;
    return answer;
}
int main(void)
{
    cout << solution(10);
}