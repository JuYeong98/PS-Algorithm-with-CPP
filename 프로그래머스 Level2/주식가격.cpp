#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int sec = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        int a = prices[i];
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (a <= prices[j])
                sec++;
            else
            {  
                sec++;
                break;
            }
        }
        answer.push_back(sec);
        sec = 0;
    }
    return answer;
}
