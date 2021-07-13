#include <string>
#include <vector>
#include <iostream>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    answer = sum / (double)arr.size();
    return answer;
}

int main(void)
{
   
}