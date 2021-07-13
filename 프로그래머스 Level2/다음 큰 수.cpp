#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;
int num_one(int n);
int solution(int n) {
    int answer = 0;
    int count = num_one(n);
    while (1)
    {
        n++;
        if (count == num_one(n))
            return n;
    }
    return n;
}
int num_one(int n)
{
    int count = 0;
    string s = bitset<20>(n).to_string();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            count++;
    }
    return count;
}
int main(void)
{
    cout << solution(78);
}
