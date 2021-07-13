#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    for (int i = 0; i < progresses.size(); i++)
    {
        int gap = (100-progresses[i]);
        if (gap % speeds[i] == 0)//������ ��������
            gap = gap / speeds[i];
        else if (gap % speeds[i] != 0) //������ �������� ������
            gap = (gap / speeds[i]) + 1;
        day.push_back(gap);
    }
    int max = day[0];
    int count = 0;
    for (int i = 0; i < progresses.size(); i++)
    {
        if (day[i] < max)//���� �Ϸ��� �ϼ��� ũ�ٸ�
        {
            count++;
        }
        else if (day[i] > max) //�ڿ� �Ϸ� �� ���� �� ũ�ٸ�
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