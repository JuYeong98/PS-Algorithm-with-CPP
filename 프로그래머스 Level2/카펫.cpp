#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = 0, height = 0;
    int sum = brown + yellow; //전체 카펫의 개수
    for (int i = 1; ; i++)
    {
        int a = yellow / i;//세로 길이 
        int b = yellow / a;
        int sum_temp = (a + 2) * (b + 2);
        int sum_yellow = a * b;
        int sum_brown = (2 * a) + (2 * b) + 4;
        if ((sum == sum_temp) && (sum_yellow == yellow) && (sum_brown == brown)&&(b>=a))
        {
            answer.push_back(b + 2);
            answer.push_back(a + 2);
            return answer;
        }
    }
    return answer;
}