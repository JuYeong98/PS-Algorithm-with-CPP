#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> a;
    int b = n;
    while (n >= 1)
    {
        int input = n % 10;
        n /= 10;
        a.push_back(input);
    }
    sort(a.begin(), a.end(),greater<int>());
    for (int i = 0; i < a.size(); i++)
    {
        answer =answer+ a[i] * pow(10, a.size()-1-i);
    }

    return answer;
}
int main(void)
{

}