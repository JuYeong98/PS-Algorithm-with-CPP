#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    cout << n << endl;
    while (n >= 1)
    {
        int input = n % 10;
        n /= 10;
        answer.push_back(input);
    }

    return answer;
}

int main(void)
{
    long long n = 9876543210;
    solution(9876543210);
    return 0;
}