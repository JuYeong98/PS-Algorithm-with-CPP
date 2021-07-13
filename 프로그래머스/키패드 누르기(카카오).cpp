#include <string>
#include <vector>

using namespace std;
int dist(int a, int b);
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = -1;
    int right = -2;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.append("L");
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.append("R");
            right = numbers[i];
        }
        else if (numbers[i]==2||numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0)
        {
            if (dist(left, numbers[i]) > dist(right, numbers[i]))
            {

                answer.append("R");
                right = numbers[i];
            }
            else if (dist(left, numbers[i]) < dist(right, numbers[i]))
            {
                answer.append("L");
                left = numbers[i];
            }
            else
            {
                if (hand == "right")
                {
                    answer.append("R");
                    right = numbers[i];
                }
                else if (hand == "left")
                {
                    answer.append("L");
                    left = numbers[i];
                }
            }
            
        }
    }
    return answer;
}
int dist(int a, int b)
{
    int d = 0;
    
    if (b == 2)
    {
        if (a == 1 || a == 3 || a == 5)
            d = 1;
        else if (a == 4 || a == 6||a==8)
            d = 2;
        else if (a == 7 || a == 9||a==0)
            d = 3;
        else if (a == -1||a==-2)//a==-1,-2 이면 각각 *이랑 #
            d = 4;
     }
    else if (b == 5)
    {
        if (a == 2 || a == 4 || a == 6 || a == 8)
            d = 1;
        else if (a == 1 || a == 3 || a == 7 || a == 9||a==0)
            d = 2;
        else if (a == -1 || a == -2)
            d = 3;
    }
    else if (b == 8)
    {
        if (a == 5 || a == 7 || a == 0 || a == 9)
            d = 1;
        else if (a == 4 || a == 6||a==-1||a==-2||a==2)
            d = 2;
        else if (a == 1 || a == 3)
            d = 3;
    }
    else
    {
        if (a == 8||a==-1||a==-2)
            d = 1;
        else if (a==5||a == 7 || a == 9)
            d = 2;
        else if (a==2||a == 4 || a == 6)
            d = 3;
        else if (a == 1 || a == 3)
            d = 4;
    }
    return d;
}