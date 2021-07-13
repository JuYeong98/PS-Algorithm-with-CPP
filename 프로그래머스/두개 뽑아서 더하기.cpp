#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int len = numbers.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (i != j)
            {
                answer.push_back(numbers[i] + numbers[j]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
   
    return answer;
}

int main(void)
{
    vector<int>a = { 2,1,3,4,1 };
    
}