#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long int n = num;
    while (n != 1)
    {
        
        if (n % 2 == 0)//Â¦¼ö¸é
        {
            n =n/ 2;
            answer++;
        }
        else//È¦¼ö¸é
        {
            n = (n * 3);
            n++;
            answer++;
        }
        if (answer >= 500)
        {
            answer = -1;
            break;
        }
    }
  
    return answer;
}
int main(void)
{
    cout << solution(626331);
}