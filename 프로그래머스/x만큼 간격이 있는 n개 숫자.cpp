#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int input = x;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(input);
        input += x;
    }
    return answer;
}
int main(void)
{

}