#include <string>
#include <vector>
bool help(int start, int n);
using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (help(i, n))
            answer++;
    }
    return answer;
}
bool help(int start,int n)
{
    int sum = 0;
    for (int i = start; i <= n; i++)
    {
        sum += i;
        if (sum > n)
        {
            return false;
        }
        else if (sum == n)
        {
            return true;
        }
    }
}