#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int big, small;
    int a, b;
    if (n < m)
    {
        small = n;
        big = m;
    }
    else
    {
        small = m;
        big = n;
    }
    for (int i = 1; i <= small; i++)
    {
        if (big % i == 0 && small % i == 0)
        {
            a = i;
        }
    }
    b = (big * small) / a;
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}
int main(void)
{

}