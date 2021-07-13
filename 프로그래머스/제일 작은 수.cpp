#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0];
    int memory=0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            memory = i;
        }
    }
    arr.erase(arr.begin()+memory);
    if (arr.size() == 0)
    {
        arr.push_back(-1);
    }
    return arr;
}
int main(void)
{

}