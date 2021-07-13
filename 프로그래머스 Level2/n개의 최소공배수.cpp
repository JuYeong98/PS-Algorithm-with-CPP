#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int lcm(int a, int b);


int solution(vector<int> arr) {
    while (arr.size() != 1)
    {
        int a = lcm(arr[arr.size()-1], arr[arr.size()-2]);
        arr.pop_back();
        arr.pop_back();
        arr.push_back(a);
    }
    return arr[0];
}
int lcm(int a, int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int r;
    while (min != 0)
    { r = max % min; 
    max = min;
    min = r;
    }
    return (a * b) / max;
}
