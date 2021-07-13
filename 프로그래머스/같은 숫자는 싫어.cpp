#include <vector>
#include <iostream>

using namespace std;

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    vector<int>::iterator iter;
    for (iter = arr.begin(); iter != arr.end(); ++iter) {
        if ((iter + 1) == arr.end() && (*iter) == *(iter - 1))
        {
            answer.push_back(*iter);
        }
        else if (*iter == *(iter + 1))
        {
            continue;
        }
        else {
            answer.push_back(*iter);
        }
    }

    return answer;
}
int main(void)
{
  
}