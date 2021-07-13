#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    for (int i = 0; i < progresses.size(); i++)
    {
        int gap = (100-progresses[i]);
        if (gap % speeds[i] == 0)//나누어 떨어지면
            gap = gap / speeds[i];
        else if (gap % speeds[i] != 0) //나누어 떨어지지 않으면
            gap = (gap / speeds[i]) + 1;
        day.push_back(gap);
    }
    int max = day[0];
    int count = 0;
    for (int i = 0; i < progresses.size(); i++)
    {
        if (day[i] < max)//전에 완료한 일수가 크다면
        {
            count++;
        }
        else if (day[i] > max) //뒤에 완료 일 수가 더 크다면
        {
            answer.push_back(count);
            count = 1;
            max = day[i];
        }
        if (i == progresses.size() - 1)
        {
            answer.push_back(count)
        }
    }
    return answer;
}