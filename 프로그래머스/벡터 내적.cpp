#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int len = a.size();
    int len2 = b.size();
    if (len == len2)
    {
        for (int i = 0; i < len; i++)
        {
            answer += a[i] * b[i];
        }
    }
    return answer;
}

int main(void)
{

}