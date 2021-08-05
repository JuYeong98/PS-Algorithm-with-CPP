#include <iostream>

using namespace std;
int is_matching(int a, int b) {
    int big = a > b ? a : b; //큰 수를 big으로 함
    int diff = (a - b) * (a - b);
    if (big % 2 == 0 && diff == 1)
        return 1;
    else
        return 0;
}
int win(int a) {
    if (a % 2 == 1)
        return (a / 2) + 1;
    else
        return a / 2;
}
int solution(int n, int a, int b)
{
    int answer = 0;
    while (1) {
        answer++;
        if (is_matching( a,  b))
            return answer;
        else {
            a = win(a); b = win(b);
        }
    }
    
    return answer;
}