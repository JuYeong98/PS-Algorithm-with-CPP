#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int find_num(vector<int>citations, int num);
int find_same(vector<int>citations, int num);
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int i = 0;
    int front = 0;
    int end = 0;
    while (1)
    {
        front=find_num(citations, i);// i 이하의 수
        end = citations.size() - find_same(citations, i);
        //cout << "i:" << i << "  front:" << front << "  end:" << end << endl;
        if (front <= i && end >= i)
            answer = i;
        if (i == citations[citations.size() - 1])
            break;
        i++;
    }
    return answer;
}
int find_num(vector<int>citations,int num)
{
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[0] > num)
            return 0;
        else if (citations[i] <= num)
            continue;
        else if (citations[i] > num)
            return i;
    }
}
int find_same(vector<int>citations, int num)
{
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[0] > num)
            return 0;
        else if (citations[i] == num)
            return i;
        else if (citations[i] > num)
            return i;
    }
}